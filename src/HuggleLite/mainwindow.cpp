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

using namespace HuggleLite;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
    this->ui->systemLog->setVisible(false);
    this->SystemLog("HuggleLite " + QString(HUGGLE_LITE_VERSION));
}

MainWindow::~MainWindow()
{
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
