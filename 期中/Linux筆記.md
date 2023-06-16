~ 家目錄 home directory
pwd 到家目錄 print work directory
到上一個目錄 -
清除 clear
sudo 在執行的階段轉成管理者
一般使用者 $
超級使用者 #

防火牆
systemctl stop firewalld
systemctl disable firewalld
disabled 為開機不啟動
enabled 為開機啟動
systemctl status firewalld 檢查防火牆
![image](https://github.com/a920217/-/assets/99935105/0dcecf3d-0eb7-461a-a838-9090404b117c)




外部連線
systemctl start sshd 開啟SSH
systemctl status sshd


建構在網頁上
systemctl start httpd
systemctl status httpd
cd /var/www/html
echo “hi” > hi.htm

