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
#include <apiquery.hpp>
#include <core.hpp>

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
