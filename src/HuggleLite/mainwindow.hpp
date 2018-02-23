//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "definitions.hpp"
#include <QMainWindow>
#include <QTimer>

namespace Huggle
{
    class HuggleFeed;
    class WikiSite;
}

namespace Ui
{
    class MainWindow;
}

namespace HuggleLite
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

        public:
            explicit MainWindow(QWidget *parent = 0);
            ~MainWindow();
            void SystemLog(QString text);
            void ChangeProvider(Huggle::WikiSite *site, Huggle::HuggleFeed *provider);
            void SwitchAlternativeFeedProvider(Huggle::WikiSite *site);
            void SetHtml(QString html);

        private slots:
            void on_actionSystem_log_triggered();
            void on_actionExit_triggered();
            void on_actionDebug_info_triggered();
            void OnInfoTimerTick();
            void on_actionTest_diff_triggered();

        private:
            bool debugVisible = false;
            QTimer *tDebug;
            Ui::MainWindow *ui;
            QString systemLogBuffer;
    };
}

#endif // MAINWINDOW_HPP
