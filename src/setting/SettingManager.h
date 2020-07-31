﻿#ifndef SETTINGMANAGER_H
#define SETTINGMANAGER_H

#include <QObject>
#include <QSettings>
#include <QDateTime>

#include "RovApplication.h"
#include "RovToolBox.h"
#include "VideoManager.h"



class SettingManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString uri READ getServerUri WRITE setServerUri NOTIFY serverUriChanged)
    Q_PROPERTY(QString port READ getServerPort WRITE setServerPort NOTIFY serverPortChanged)
    Q_PROPERTY(QString video_uri READ getVideoPort WRITE setVideoUrl NOTIFY videoUriChanged)
    Q_PROPERTY(QString video_port READ getVideoUrl WRITE setVideoPort NOTIFY videoPortChanged())
public:
    SettingManager();
    ~SettingManager();
    void InitSettings();



    typedef enum {
        UDP265,
        UDP264,
        TCP
    } STREAMING_TYPE;


public slots:
    void setServerUri(QString u);
    void setServerPort(QString p);
    void setVideoUrl(const QString u);
    void setVideoPort(const QString p);
    void setThermalVideoUrl(const QString u);
    void setThermalVideoPort(const QString p);
    void setAudioUrl(const QString u);
    void setAudioPort(const QString p);
    void setStreamType(const int t = STREAMING_TYPE::UDP265);
    void setStreamType_2(const int t = STREAMING_TYPE::UDP265);
    void udpSettings();

    QString getServerUri()  {return uri;}
    QString getServerPort() {return port;}
    QString getVideoPort()  {return this->video_port;  };
    QString getVideoUrl()   {return this->video_uri;   };
    QString getThermalVideoPort()  {return this->thermal_video_port;  };
    QString getThermalVideoUrl()   {return this->thermal_video_uri;   };
    QString getAudioPort()  {return this->audio_port;  };
    QString getAudioUrl()   {return this->audio_uri;   };
    int     getStreamType() {return this->stream_type; };
    int     getStreamType_2() {return this->stream_type_2; };
    QString getVideoPath()  {return this->videoSavePath; };
    QString getImagePath();

private:
    QString uri;
    QString port;

    QString video_uri;
    QString video_port;
    QString thermal_video_uri;
    QString thermal_video_port;
    QString audio_uri;
    QString audio_port;

    QSettings* read_write;

    QString videoSavePath;
    QString grapImageSavePath;

    STREAMING_TYPE stream_type;
    STREAMING_TYPE stream_type_2;

    int win_x;
    int win_y;
    int win_w;
    int win_h;
signals:
    void serverUriChanged();
    void serverPortChanged();
    void videoUriChanged();
    void videoPortChanged();
};

#endif // SETTINGMANAGER_H
