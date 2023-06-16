反斜線跟括號是互通的 此指令就可以建造與時間相關的檔案

![](https://hackmd.io/_uploads/rJ0ay0MU2.jpg)

NTP protocol 主要為時間矯正用

(network time protocol)

synchronization 同步

cluster 集群 有很多很多的server

ntpdate 指令 會去跟時間伺服器(NTP server)做同步時間的部分

在使用ntpdate指令之前先確認時間 timezones

![](https://hackmd.io/_uploads/BJslfAfI3.jpg)

顯示歷史的指令 history

執行特定歷程的指令 !數字

![](https://hackmd.io/_uploads/HJePzAfI3.jpg)

!keyword 會往上匹配相關的指令

![](https://hackmd.io/_uploads/r1TV7RGL3.jpg)

大部分的紀錄檔都在 /var/log 的環境之下 

如果安裝完server,卻無法連接? 如何debug:

1. systemctl status 伺服器  查看狀態, 如果已經running,但還是無法連接
2. 查看防火牆,selinux
3. 檢查port number

查看對應的port

![](https://hackmd.io/_uploads/HkefrRfU2.jpg)

網頁伺服器狀態
1XX 資訊
2XX 成功
3XX 重新導向
4XX 用戶端錯誤
5XX 伺服器錯誤

### 9-4 考試重點

(1 * * * )每小時執行 1:01 2:01 3:01
(*/ * * * *) 每分鐘執行 1:01 1:02 1:03

# ┌───────────── 分鐘   (0 - 59)
# │ ┌─────────── 小時   (0 - 23)
# │ │ ┌───────── 日     (1 - 31)
# │ │ │ ┌─────── 月     (1 - 12)
# │ │ │ │ ┌───── 星期幾 (0 - 7，0 是週日，6 是週六，7 也是週日)
# │ │ │ │ │
# * * * * * /path/to/command

設定排程

29 9 15 8 * 8月15號早上9點29分

0 17 10 * * 每個月的10日，下午五點

0 4 * * 6 每個星期六零晨4時

1,31 17 10 * 17:01 17:31

例子:

# 每天早上 8 點 30 分執行
30 08 * * * /home/gtwang/script.sh --your --parameter

# 每週日下午 6 點 30 分執行
30 18 * * 0 /home/gtwang/script.sh --your --parameter

# 每週日下午 6 點 30 分執行
30 18 * * Sun /home/gtwang/script.sh --your --parameter

# 每年 6 月 10 日早上 8 點 30 分執行
30 08 10 06 * /home/gtwang/script.sh --your --parameter

# 每月 1 日、15 日、29 日晚上 9 點 30 分各執行一次
30 21 1,15,29 * * /home/gtwang/script.sh --your --parameter

# 每隔 10 分鐘執行一次
*/10 * * * * /home/gtwang/script.sh --your --parameter

# 從早上 9 點到下午 6 點，凡遇到整點就執行
00 09-18 * * * /home/gtwang/script.sh --your --parameter

![](https://hackmd.io/_uploads/S1MD-kXI3.jpg)

soft limit 軟性限制 hard limit 硬性限制

磁碟配額設定

![](https://hackmd.io/_uploads/rJtuPJmUh.jpg)

### 考試範圍 

slink

hlink

find

5-4 會考

https://blog.gtwang.org/linux/unix-linux-find-command-examples/

第六章 字元設備

使用者資訊 /etc/passwd

密碼 /etc/shadow

檔案的權限 目錄的權限 

![](https://hackmd.io/_uploads/rkHKWg7L3.jpg)

![](https://hackmd.io/_uploads/SyH5Wx7Un.jpg)

前景 背景的工作

壓縮 打包 解壓縮

掛載光碟片

mount -t ios9660 /dev/cdrom /media/cdrom

格式化

mkfs -t xfs /dev/sdb1

grep 的用法

新增使用者 新增群組

id 使用者資訊

查看使用者
id username

加入群組
![](https://hackmd.io/_uploads/S1erFG05Lh.png)

加入附載群組
![](https://hackmd.io/_uploads/B1mqMCqU3.png)

變更使用者群組

usermod -G 群組名稱 使用者名稱

wc 觀看檔案有幾行
