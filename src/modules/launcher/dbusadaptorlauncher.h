#ifndef DBUSADAPTORLAUNCHER_H
#define DBUSADAPTORLAUNCHER_H

#include "launcher.h"

#include <QtCore/QObject>
#include <QtCore/QMetaObject>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Adaptor class for interface org.deepin.dde.daemon.Launcher1
 */
class DBusAdaptorLauncher: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.deepin.dde.daemon.Launcher1")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"org.deepin.dde.daemon.Launcher1\">\n"
"    <method name=\"GetAllItemInfos\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"itemInfoList\"/>\n"
"    </method>\n"
"    <method name=\"GetAllNewInstalledApps\">\n"
"      <arg direction=\"out\" type=\"as\" name=\"apps\"/>\n"
"    </method>\n"
"    <method name=\"GetDisableScaling\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"id\"/>\n"
"      <arg direction=\"out\" type=\"b\" name=\"value\"/>\n"
"    </method>\n"
"    <method name=\"GetItemInfo\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"id\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"itemInfo\"/>\n"
"    </method>\n"
"    <method name=\"GetUseProxy\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"id\"/>\n"
"      <arg direction=\"out\" type=\"b\" name=\"value\"/>\n"
"    </method>\n"
"    <method name=\"IsItemOnDesktop\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"id\"/>\n"
"      <arg direction=\"out\" type=\"b\" name=\"result\"/>\n"
"    </method>\n"
"    <method name=\"RequestRemoveFromDesktop\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"id\"/>\n"
"      <arg direction=\"out\" type=\"b\" name=\"ok\"/>\n"
"    </method>\n"
"    <method name=\"RequestSendToDesktop\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"id\"/>\n"
"      <arg direction=\"out\" type=\"b\" name=\"ok\"/>\n"
"    </method>\n"
"    <method name=\"RequestUninstall\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"id\"/>\n"
"    </method>\n"
"    <method name=\"SetDisableScaling\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"id\"/>\n"
"      <arg direction=\"in\" type=\"b\" name=\"value\"/>\n"
"    </method>\n"
"    <method name=\"SetUseProxy\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"id\"/>\n"
"      <arg direction=\"in\" type=\"b\" name=\"value\"/>\n"
"    </method>\n"
"    <method name=\"LaunchWithTimestamp\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"desktopFile\"/>\n"
"      <arg direction=\"in\" type=\"i\" name=\"time\"/>\n"
"      <arg direction=\"out\" type=\"b\" name=\"value\"/>\n"
"    </method>\n"
"    <method name=\"RemoveAutostart\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"desktopFile\"/>\n"
"      <arg direction=\"out\" type=\"b\" name=\"value\"/>\n"
"    </method>\n"
"    <method name=\"AddAutostart\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"desktopFile\"/>\n"
"      <arg direction=\"out\" type=\"b\" name=\"value\"/>\n"
"    </method>\n"
"    <signal name=\"ItemChanged\">\n"
"      <arg type=\"s\" name=\"status\"/>\n"
"      <arg type=\"s\" name=\"itemInfo\"/>\n"
"      <arg type=\"x\" name=\"categoryID\"/>\n"
"    </signal>\n"
"    <signal name=\"NewAppLaunched\">\n"
"      <arg type=\"s\" name=\"appID\"/>\n"
"    </signal>\n"
"    <signal name=\"UninstallSuccess\">\n"
"      <arg type=\"s\" name=\"appID\"/>\n"
"    </signal>\n"
"    <signal name=\"UninstallFailed\">\n"
"      <arg type=\"s\" name=\"appId\"/>\n"
"      <arg type=\"s\" name=\"errMsg\"/>\n"
"    </signal>\n"
"    <property access=\"readwrite\" type=\"b\" name=\"Fullscreen\"/>\n"
"    <property access=\"readwrite\" type=\"i\" name=\"DisplayMode\"/>\n"
"  </interface>\n"
        "")
public:
    DBusAdaptorLauncher(QObject *parent);
    virtual ~DBusAdaptorLauncher();

    Launcher *parent() const;

public: // PROPERTIES
    Q_PROPERTY(int DisplayMode READ displayMode WRITE setDisplayMode NOTIFY DisplayModeChanged)
    int displayMode() const;
    void setDisplayMode(int value);

    Q_PROPERTY(bool Fullscreen READ fullscreen WRITE setFullscreen NOTIFY FullScreenChanged)
    bool fullscreen() const;
    void setFullscreen(bool value);

public Q_SLOTS: // METHODS
    bool AddAutostart(const QString &desktopFile);
    QString GetAllItemInfos();
    QStringList GetAllNewInstalledApps();
    bool GetDisableScaling(const QString &id);
    QString GetItemInfo(const QString &id);
    bool GetUseProxy(const QString &id);
    bool IsItemOnDesktop(const QString &id);
    bool LaunchWithTimestamp(const QString &desktopFile, int time);
    bool RemoveAutostart(const QString &desktopFile);
    bool RequestRemoveFromDesktop(const QString &id);
    bool RequestSendToDesktop(const QString &id);
    void RequestUninstall(const QString &id);
    void SetDisableScaling(const QString &id, bool value);
    void SetUseProxy(const QString &id, bool value);
Q_SIGNALS: // SIGNALS
    void ItemChanged(const QString &status, const QString &itemInfo, qlonglong categoryID);
    void NewAppLaunched(const QString &appID);
    void UninstallFailed(const QString &appId, const QString &errMsg);
    void UninstallSuccess(const QString &appID);

    void DisplayModeChanged(int mode);
    void FullScreenChanged(bool isFull);
};

#endif