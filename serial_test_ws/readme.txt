package:cmd_vel_pub
node: cmd_vel_pub
作用：发布/cmd_vel topic 用于串口测试

package:serial_test
node: serial_test
作用：移植于ros上的串口通信，接受/cmd_vel并发布于串口。
		 需要先将udev/stm32.rules cp 至 /etc/udev/rules.d 并重启
