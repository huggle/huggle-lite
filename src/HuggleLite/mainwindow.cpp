//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "resources.hpp"
#include <apiquery.hpp>
#include <configuration.hpp>
#include <core.hpp>
#include <wikisite.hpp>
#include <hugglefeed.hpp>
#include <hugglefeedproviderirc.hpp>
#include <hugglefeedproviderwiki.hpp>
#include <hugglefeedproviderxml.hpp>

using namespace HuggleLite;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
    this->ui->systemLog->setVisible(false);
    this->ui->lDebug->setVisible(false);
    this->ui->lDebug->setText("");
    this->SystemLog("HuggleLite " + QString(HUGGLE_LITE_VERSION));
    this->tDebug = new QTimer(this);
    connect(this->tDebug, SIGNAL(timeout()), this, SLOT(OnInfoTimerTick()));
    this->tDebug->start(HUGGLE_TIMER);
    this->SetHtml("<h1>Welcome to Huggle Lite</h1><big>Loading diffs...</big>");
    //this->ChangeProvider(hcfg->Project, new Huggle::HuggleFeedProviderXml(hcfg->Project));
    this->ChangeProvider(hcfg->Project, new Huggle::HuggleFeedProviderWiki(hcfg->Project));
}

MainWindow::~MainWindow()
{
    delete this->tDebug;
    delete this->ui;
}

void MainWindow::SystemLog(QString text)
{
    this->systemLogBuffer = text + "\n" + this->systemLogBuffer;
    this->ui->systemLog->setPlainText(this->systemLogBuffer);
}

void MainWindow::ChangeProvider(Huggle::WikiSite *site, Huggle::HuggleFeed *provider)
{
    // This code is deliberatery overtaken from actual Huggle
    if (site->Provider != nullptr)
    {
        if (site->Provider->IsWorking())
            site->Provider->Stop();
        // we should be safe to delete here, although some providers
        // might need to be checked if they actually stopped :/
        delete site->Provider;
    }
    site->Provider = provider;
    this->SystemLog("Changed provider to " + provider->ToString());

    // try to launch the provider now
    if (!site->Provider->Start())
    {
        this->SystemLog("Provider failed: " + provider->ToString());
        // provider didn't start so we need to find alternative
        this->SwitchAlternativeFeedProvider(site);
    }
}

void MainWindow::SwitchAlternativeFeedProvider(Huggle::WikiSite *site)
{
    if (site->Provider == nullptr)
    {
        this->ChangeProvider(site, new Huggle::HuggleFeedProviderXml(site));
        return;
    }
    switch (site->Provider->GetID())
    {
        case HUGGLE_FEED_PROVIDER_IRC:
            // fallback to wiki provider
            this->ChangeProvider(site, new Huggle::HuggleFeedProviderWiki(site));
            return;
        case HUGGLE_FEED_PROVIDER_WIKI:
            // no more solutions
            this->SystemLog("No more solutions for alternative provider for " + site->Name);
            return;
        case HUGGLE_FEED_PROVIDER_XMLRPC:
            // fallback to irc provider
            this->ChangeProvider(site, new Huggle::HuggleFeedProviderIRC(site));
            return;
    }
}

void MainWindow::SetHtml(QString html)
{
    this->ui->diffView->setText(html);
}

void HuggleLite::MainWindow::on_actionSystem_log_triggered()
{
    this->ui->systemLog->setVisible(this->ui->actionSystem_log->isChecked());
}

void HuggleLite::MainWindow::on_actionExit_triggered()
{
    Huggle::Core::HuggleCore->Shutdown();
    QApplication::quit();
}

void HuggleLite::MainWindow::on_actionDebug_info_triggered()
{
    this->debugVisible = this->ui->actionDebug_info->isChecked();
    this->ui->lDebug->setVisible(this->debugVisible);
}

void MainWindow::OnInfoTimerTick()
{
    // Refresh debug information, but only if the debug panel is visible (save some CPU)
    if (!this->debugVisible)
        return;

    this->ui->lDebug->setText("QGC: " + QString::number(Huggle::Core::HuggleCore->gc->list.count()));
}

void HuggleLite::MainWindow::on_actionTest_diff_triggered()
{
    this->SetHtml(QString(Resources::LoadResource("/huggle/text/Resources/test_diff.htm")));
}
