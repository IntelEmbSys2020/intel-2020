# Smart Drone for Mask Recognition
**Award: National Third Prize**

## Abstract

In this project, we build the AI-BoxX Gen.1 development board working environment on the unmanned aerial vehicle (UAV) flight platform, and use OpenVINO-accelerated convolutional neural network for the mask and facial feature recognition. Our UAV can patrol in crowded public places such as squares to identify epidemics diffusion behaviors and call down to the target person.
Given a patrol range by the user, the aircraft will automatically patrol and collect real-time images. The onboard camera is connected to the Intel development board through the USB3.0 interface, and transmits real-time data to the AI-BoxX Gen.1 work platform on the ground using 4G communication. Our face mask detection model, a lightweight model based on the SSD Convolutional Neural Network(CNN), determines whether people are wearing masks properly, and efficiently picks out the faces without a mask. The project can also use the SSR-Net model to judge and predict the gender and age of the selected faces, and send the identified features to the semantic synthesis template, and then call the real-time speech synthesis algorithm of iFLYTEK software to synthesize the prompt sound. After that, through the audio interface of the development board and the external power amplifier, we can accurately remind the target person. At the same time, the development board parses the PIXHAWK flight control in real time through the MAVSDK and issues movement instructions. A highlight of the project is that it can determine whether to automatically return for wireless charging based on the real-time power. When the power is lower than the threshold, our UAV will automatically return and automatically recognize the apron to land on. After landing, it will be charged through the built-in wireless charging module, and there is no need for personnel during the whole process. If necessary, users can remotely control it through the 4G-LTE network, quickly adjust the aircraft status and obtain real-time information on the ground station UI interface.
Besides reducing the cost of manpower management, this intelligent identification aircraft can effectively identify behaviors that are not conducive to epidemic control without interfering in the normal activities of the people in public places, and give reminders to target groups in order to maintain the health and safety of the general public.

## Key words

OpenVINO, CNN, image recognition, feature extraction, speech synthesis, automation, 4G-LTE

## Main Features

* Automatic Patrol; 
* Real-time Control;
* AI Recognition; 
* Unattended; 
* Precise Propaganda; 
* Image Synchronization

### Mask Detection

![image](https://user-images.githubusercontent.com/43924016/130090394-a070bf1c-7b8c-4de1-bb5c-caa9db7be2b9.png)
Mask Recognition Module. 
SSD network: one stage, lightweight, fast. 
Precision: 0.896 for face with mask, 0.919 for face without mask.
![image](https://user-images.githubusercontent.com/43924016/130090895-cd6064f9-c7c8-4460-aaf6-c4d903edc663.png)
![image](https://user-images.githubusercontent.com/43924016/130090930-a2d308fe-8f8e-4dc1-a6da-e35e69862c7f.png)


### Face Feature Extraction
![image](https://user-images.githubusercontent.com/43924016/130090622-2c20522b-4fd3-4a14-9f45-c37d043e11c8.png)
SSR-Net: multiclass problem. 
**MegaAge-Asian dataset:**
Containing 40,000 face images of Asians with ages from 0 to 70
![image](https://user-images.githubusercontent.com/43924016/130091056-34660be4-dcfa-4159-a57c-d0143d4bbf41.png)


# 概要

本作品主要实现内容为：可在公众场合（比如：购物广场）上，由无人机搭载视觉识别平台，实现路人防疫状态检查，功能包括但不限于：佩戴口罩情况识别、路人簇拥识别、对路人发起语音提示警告。

扩展功能为：可实现多机协同交替工作交替充电；完全无人值守，可通过NB-IoT联网，远程控制；无线充电，提高无人机的自动化水平

## 实现梯度

1. 口罩/人脸识别
2. 衣服颜色识别
3. 语义合成模板or语音合成SDK
4. 喊话（音频放大器）
5. 无人机搭建
6. 无人机超声波避障
7. 移动网络通信+定位
8. 定点循环飞行
9. 联调
10. 脸脸距离（VO）（排队人群）
11. 停机坪识别对准（“X”字符）
12. 自动无线充电
13. 给定广场范围判断

### 扩展内容发展

1. 房间内随机飞行
2. 多机协同工作（交替充电、飞行）
3. 电量检测

## 分工

佟：

1. 口罩识别
2. 定点飞行
3. 停机坪识别对准
4. 语音模块驱动

江：

> 全硬件

1. 无人机组装调试
2. 喇叭功放
3. 电源
4. 无线充电
5. 语音合成模块
6. 电量检测
7. 语音合成SDK

陈：

1. 人物特征识别（性别、衣服颜色etc）
2. 脸脸距离
3. 语义合成模板
4. 语音合成SDK
5. 给定广场范围判断

## 需要仪器/物资

- 示波器
- 电源
- 信号发生器
- 焊台
- 无人机体
- 航空锂电池+充电器
- 全局快门摄像头
- STM32开源飞控
- 大喇叭+音频放大器（D类）
- 电源转换板

## 软件细节

> 注意使用OpenVino加速,[教程](https://software.intel.com/content/www/cn/zh/develop/topics/iot/training/go-to-market-with-openvino.html?cid=em&source=elo&campid=iags_PRC_iagsdrsiot_ZH-Hans_2020_IoT20_Campaign_C-MKA-16416_T-MKA-17806&content=iags_PRC_iagsdrsiot_EMN_ZH-Hans_2020_IoT_1_C-MKA-16416_T-MKA-17806&elq_cid=6499999&em_id=56207&elqrid=92280acaff7d410885706fb331104a4e&elqcampid=37215&erpm_id=9621834)

### 场景假设

1. 室内
2. 室外
   1. 广场类（GPS打标）
   2. 人工飞行，记录路线

### 脸脸距离

- 识别整个人体
- 由人体大小线性变换距离

### 口罩/人脸识别

## 硬件细节

### 定位通信

1. 学长推荐的定位通信[二合一模块](http://www.openluat.com/Product/gnssgprs/Air800.html)。使用GPRS+GPS，考虑到今年年底2G会被全拆掉，暂时不考虑该方案
2. 淘宝买二合一通信定位模块[NB-IOT+Beidou](https://detail.tmall.com/item.htm?id=602693366424&price=18-69&sourceType=item&sourceType=item&suid=e2614846-4394-4e58-9aec-b84cdbbfe5ec&shareUniqueId=1304861063&ut_sk=1.XmxMu9Ues2gDAKUWAWAfAl73_21646297_1592976011846.Copy.1&un=84fe8c086325801f0f8768acc41474bb&share_crt_v=1&spm=a2159r.13376460.0.0&sp_tk=4oKsZzF6czFFU3M5SXTigqw=&cpp=1&shareurl=true&short_name=h.VpijOXg&sm=d986e8&app=chrome)
3. 北斗定位模块+NB-IoT通信模块。该方案主要优势为：目前二合一模块都是2.5m精度，若采用分离方案可以选择精度更高的双频双模定位，1.2m精度

待完成工作

- [ ] 模块购买
- [ ] 天线设计
- [ ] 模块电源设计
- [ ] 模块驱动程序
- [ ] 云服务器转接

### 无人机

1. 基地嫖机械结构+电机
2. 淘宝买飞控

待完成工作

- [ ] 基地无人机型号挑选
- [ ] 电机白嫖or购买
- [ ] 无人机电池和充电器
- [ ] 无人机开源飞控选型
- [ ] 无人机飞行调试

### 喊话

1. 百度SDK+USB音响
2. UART+语音合成模块+功放（PlanB）

待完成工作

- [ ] 确认开发板是否有音频接口

### 电源板

- [ ] 开发板供电（待确认）
- [ ] 飞控供电
- [ ] 电机供电
- [ ] 电池电量检测
- [ ] 上位机通信（报告电源情况）
- [ ] 无线充电模式

### 无线充电

1. 视觉对准（摄像头）
2. 淘宝模块100W[24V4A模块](https://m.tb.cn/h.Vp5gQER?sm=6e354)，注意：模块小于7mm距离烧坏

待完成工作

- [ ] 模块购买
- [ ] 模块充电测试（记录模块实际工作数据）

### 视觉

- [ ] 开发板接口确认（3.5mm音频+USB3+供电方式）
- [ ] 摄像头挑选
- [ ] 平台搭建、操作系统安装
- [ ] 摄像头驱动适配
