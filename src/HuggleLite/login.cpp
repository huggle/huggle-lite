//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "login.hpp"
#include "ui_login.h"
#include "mainwindow.hpp"
#include <configuration.hpp>
#include <wikisite.hpp>

using namespace HuggleLite;

Login::Login(QWidget *parent) : QDialog(parent), ui(new Ui::Login)
{
    this->ui->setupUi(this);
}

Login::~Login()
{
    delete this->ui;
}

void HuggleLite::Login::on_bAnon_clicked()
{
    // For testing
    hcfg->Project = new Huggle::WikiSite("testwiki", "test.wikipedia.org/", "wiki/", "w/", true, false, "#test.wikipedia", "test.wikipedia.org", "#testwiki");
    hcfg->Project->XmlRcsName = "test.wikipedia.org";
    MainWindow *w = new MainWindow();
    w->showMaximized();
    this->close();
}
