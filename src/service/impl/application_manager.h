#ifndef A2862DC7_5DA3_4129_9796_671D88015BED
#define A2862DC7_5DA3_4129_9796_671D88015BED

#include "../../modules/startmanager/startmanager.h"
#include "../../modules/socket/server.h"
#include "../../modules/methods/process_status.hpp"

#include <QObject>
#include <QDBusObjectPath>
#include <QList>
#include <QMap>
#include <QDBusContext>

class Application;
class ApplicationInstance;
class ApplicationManagerPrivate : public QObject
{
    Q_OBJECT
    ApplicationManager *q_ptr = nullptr;
    Q_DECLARE_PUBLIC(ApplicationManager);

    QList<QSharedPointer<Application>> applications;
    Socket::Server server;
    std::multimap<std::string, QSharedPointer<ApplicationInstance>> tasks;
    StartManager *startManager;
    std::vector<std::string>    virtualMachines;
    const std::string           virtualMachePath;
    const std::string           section;
    const std::string           key;

public:
    ApplicationManagerPrivate(ApplicationManager *parent);
    ~ApplicationManagerPrivate();

    // 检测调用方身份
    bool checkDMsgUid();
    void init();

private:
    void recvClientData(int socket, const std::vector<char> &data);

    void write(int socket, const std::vector<char> &data);

    void write(int socket, const std::string &data);

    void write(int socket, const char c);

    void processInstanceStatus(Methods::ProcessStatus instanceStatus);
};

class ApplicationManager : public QObject, public QDBusContext
{
    Q_OBJECT
    Q_PROPERTY(QList<QDBusObjectPath> instances READ instances)
    Q_PROPERTY(QList<QDBusObjectPath> list READ list)
    QScopedPointer<ApplicationManagerPrivate> dd_ptr;
    Q_DECLARE_PRIVATE_D(qGetPtrHelper(dd_ptr), ApplicationManager)

public:
    static ApplicationManager* instance();

    void addApplication(const QList<QSharedPointer<Application>> &list);
    void launchAutostartApps();
    void processInstanceStatus(Methods::ProcessStatus instanceStatus);

Q_SIGNALS:
    void AutostartChanged(QString status, QString filePath);

public Q_SLOTS: // METHODS
    //bool Launch(QString desktopFile); deprecated
    bool AddAutostart(QString fileName);
    QStringList AutostartList();
    QString DumpMemRecord();
    bool IsAutostart(QString fileName);
    bool IsMemSufficient();
    QDBusObjectPath Launch(const QString &id, QStringList files);
    bool RemoveAutostart(QString fileName);
    bool IsPidVirtualMachine(uint32_t pid);
    void LaunchAppAction(QString desktopFile, QString action, uint32_t timestamp);
    void RunCommand(QString exe, QStringList args);
    void TryAgain(bool launch);

protected:
    ApplicationManager(QObject *parent = nullptr);
    ~ApplicationManager() override;

    QList<QDBusObjectPath> instances() const;
    QList<QDBusObjectPath> list() const;
    QDBusObjectPath GetInformation(const QString &id);
    QList<QDBusObjectPath> GetInstances(const QString &id);
    // com.deepin.StartManager
    //QString GetApps();
    void LaunchApp(QString desktopFile, uint32_t timestamp, QStringList files);
    void LaunchAppWithOptions(QString desktopFile, uint32_t timestamp, QStringList files, QMap<QString, QString> options);
    //bool LaunchWithTimestamp(QString desktopFile, uint32_t timestamp); deprecated
    void RunCommandWithOptions(QString exe, QStringList args, QMap<QString, QString> options);
    bool IsProcessExist(uint32_t pid);
};

#endif /* A2862DC7_5DA3_4129_9796_671D88015BED */
