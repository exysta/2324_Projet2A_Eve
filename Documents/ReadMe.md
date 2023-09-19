install ROS2 on Ubuntu 22.04.3 LTS

 1775  sudo apt update -y
 1776  sudo apt upgrade -y
 1777  sudo reboot now
 1778  locale
 1779  sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
 1780  export LANG=en_US.UTF-8
 1781  locale
 1782  sudo apt install software-properties-common curl gnupg lsb-release
 1783  sudo apt update -y
 1784  apt list --upgradable
 1785  sudo apt upgrade -y
 1786  ip a
 1787  ping 192.168.0.101
 1789  ip a
 1790  ping 192.168.0.101
 1791  ssh nicolas@192.168.0.101
 1792  history
 1793  sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
 1794  echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(source /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
 1795  sudo apt update
 1796  sudo apt upgrade
 1797  sudo apt install ros-humble-desktop
 1798  history
