//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <QDialog>

namespace Ui {
class Login;
}

namespace HuggleLite
{
    class Login : public QDialog
    {
        Q_OBJECT

    public:
        explicit Login(QWidget *parent = 0);
        ~Login();

    private slots:
        void on_bAnon_clicked();

    private:
        Ui::Login *ui;
    };
}

#endif // LOGIN_HPP
