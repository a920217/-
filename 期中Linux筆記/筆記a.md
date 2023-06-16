[ACL](https://ithelp.ithome.com.tw/articles/10221185)

ACL(細部權限) 讓特定的人 特定的情況 有特殊的權限 (客製化)

ACL 的控制權

使用者(user):針對使用者設定權限

群組(group):針對群組設定權限

預設屬性(mask):該目錄新建檔案/目錄時，規範新資料的最大允許權限。

設定ACL
![](https://hackmd.io/_uploads/B18pu9FS2.jpg)

切換使用者查看是否可寫入
![](https://hackmd.io/_uploads/HJvTd9KS2.jpg)

![](https://hackmd.io/_uploads/SJOT_ctSh.jpg)

可以在檔案中去做存取跟修改

![](https://hackmd.io/_uploads/BJgmsqKHn.jpg)

排成 scheduling 在甚麼時間做甚麼事 例如:每天幾點時開機一次(考試重點)

運維 維護伺服器的運作和維護

[SRE](https://ithelp.ithome.com.tw/m/articles/10264860)
網站可靠性工程

MTBF(平均故障間隔時間) MTTR(平均修復時間)

SPF (single point failure)

fault tolerance (容錯率)

防火牆的兩個工具 iptable firewalld 

firewalld 設定好後不用重啟 不會中斷連線 提供多個(zone)供管理者選擇設定

![](https://hackmd.io/_uploads/Hku6fjKrh.jpg)

觀看系統提供的zone --get-zone

目前正在使用的zone --get-active-zone

![](https://hackmd.io/_uploads/HkyD7oYB3.jpg)

防火牆規則 --zone=public --list-all

![](https://hackmd.io/_uploads/SJ1zHiFS3.jpg)

新增規則 http

![](https://hackmd.io/_uploads/ByI5YiYHh.jpg)

移除規則 http

![](https://hackmd.io/_uploads/BJ8sYiKH3.jpg)

新增port2222

![](https://hackmd.io/_uploads/Byrk5iYH2.jpg)

觀察是否在22port 

![](https://hackmd.io/_uploads/r1_ZciFSh.jpg)

[防火牆進階](https://blog.gtwang.org/linux/centos-7-firewalld-command-setup-tutorial/)

9-2 考試會考

考試必考
![](https://hackmd.io/_uploads/rk3EUnFr2.jpg)
