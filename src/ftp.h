#include "ESP32_FTPClient.h"

ESP32_FTPClient ftp(ftp_server, ftp_port, ftp_user, ftp_pass);

void uploadFile(unsigned char *data, int length, const char *name) {
    DBG("Uploading via FTP");

    ftp.OpenConnection();

    ftp.InitFile("Type I");
    ftp.ChangeWorkDir(ftp_remote_dir);
    ftp.NewFile(name);
    ftp.WriteData(data, length);
    ftp.CloseFile();
    DBG("");
}
