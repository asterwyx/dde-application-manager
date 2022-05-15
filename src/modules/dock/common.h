/*
 * Copyright (C) 2021 ~ 2022 Deepin Technology Co., Ltd.
 *
 * Author:     weizhixiang <weizhixiang@uniontech.com>
 *
 * Maintainer: weizhixiang <weizhixiang@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QMap>
#include <QDir>

const QString configDock = "com.deepin.dde.dock";
const QString configAppearance = "com.deepin.dde.appearance";
const QString keyHideMode             = "Hide_Mode";
const QString keyDisplayMode          = "Display_Mode";
const QString keyPosition             = "Position";
const QString keyIconSize             = "Icon_Size";
const QString keyDockedApps           = "Docked_Apps";
const QString keyShowTimeout          = "Show_Timeout";
const QString keyHideTimeout          = "Hide_Timeout";
const QString keyWindowSizeFashion    = "Window_Size_Fashion";
const QString keyWindowSizeEfficient  = "Window_Size_Efficient";
const QString keyWinIconPreferredApps = "Win_Icon_Preferred_Apps";
const QString keyOpacity              = "Opacity";
const QString keyPluginSettings       = "Plugin_Settings";
const QString keyForceQuitApp         = "Force_Quit_App";

const QString scratchDir = QDir::homePath() + "/.local/dock/scratch/";
const QMap<QString, QString> pathDirCodeMap {
    {"/usr/share/applications/", "/S@"},
    {"/usr/local/share/applications/", "/L@"},
    {QDir::homePath() + "/.local/share/applications", "/H@"},
    {QDir::homePath() + "/.local/dock/scratch", "/D@"},
};

const QMap<QString, QString> pathCodeDirMap {
    {"/S@", "/usr/share/applications/"},
    {"/L@", "/usr/local/share/applications/"},
    {"/H@", QDir::homePath() + "/.local/share/applications"},
    {"/D@", QDir::homePath() + "/.local/dock/scratch"},
};

// DBus服务、路径
const QString dbusService = "org.deepin.dde.daemon.Dock1";
const QString dbusPath = "/org/deepin/dde/daemon/Dock1";
const QString dbusInterface = dbusService;

const QString windowPatternsFile = "/usr/share/dde/data/window_patterns.json";
const QString desktopHashPrefix = "d:";
const QString windowHashPrefix = "w:";

const QString entryDBusObjPathPrefix = dbusPath + "/entries/";
const QString entryDBusInterface = dbusInterface + ".Entry";

// 驻留应用desktop file模板
const QString dockedItemTemplate = R"([Desktop Entry]
Name=%1
Exec=%2
Icon=%3
Type=Application
Terminal=false
StartupNotify=false
)";

const QString frontendWindowWmClass = "dde-dock";
const int configureNotifyDelay = 100;
const int smartHideTimerDelay = 400;

const int bestIconSize = 48;
const int menuItemHintShowAllWindows = 1;

const int MotifHintFunctions = 1;
const int MotifHintDecorations = 2;
const int MotifHintInputMode = 4;
const int MotifHintStatus = 8;

const int MotifFunctionNone = 0;
const int MotifFunctionAll = 1;
const int MotifFunctionResize = 2;
const int MotifFunctionMove = 4;
const int MotifFunctionMinimize = 8;
const int MotifFunctionMaximize = 16;
const int MotifFunctionClose = 32;

const QString ddeLauncherWMClass = "dde-launcher";
#endif // COMMON_H