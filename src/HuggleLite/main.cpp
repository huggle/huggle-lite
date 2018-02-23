//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "definitions.hpp"
#include "login.hpp"
#include <QApplication>
#include <configuration.hpp>
#include <core.cpp>
#include <localization.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationName("HuggleLite");
    QApplication::setOrganizationName("Wikimedia");
    Huggle::Configuration::HuggleConfiguration = new Huggle::Configuration();
    Huggle::Core::HuggleCore = new Huggle::Core();
    Huggle::Core::HuggleCore->SdkInit(Huggle::Configuration::HuggleConfiguration);
    Huggle::Localizations::HuggleLocalizations = new Huggle::Localizations();
    Huggle::Localizations::HuggleLocalizations->LocalInit("en");
    HuggleLite::Login w;
    w.showMaximized();

    return a.exec();
}
