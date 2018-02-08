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

        private:
            Ui::MainWindow *ui;
    };
}

#endif // MAINWINDOW_HPP
