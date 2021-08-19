# Smart Drone for Mask Recognition
**Award: National Third Prize**

## Abstract

In this project, we build the AI-BoxX Gen.1 development board working environment on the unmanned aerial vehicle (UAV) flight platform, and use OpenVINO-accelerated convolutional neural network for the mask and facial feature recognition. Our UAV can patrol in crowded public places such as squares to identify epidemics diffusion behaviors and call down to the target person.  

Given a patrol range by the user, the aircraft will automatically patrol and collect real-time images. The onboard camera is connected to the Intel development board through the USB3.0 interface, and transmits real-time data to the AI-BoxX Gen.1 work platform on the ground using 4G communication. Our face mask detection model, a lightweight model based on the SSD Convolutional Neural Network(CNN), determines whether people are wearing masks properly, and efficiently picks out the faces without a mask. The project can also use the SSR-Net model to judge and predict the gender and age of the selected faces, and send the identified features to the semantic synthesis template, and then call the real-time speech synthesis algorithm of iFLYTEK software to synthesize the prompt sound. After that, through the audio interface of the development board and the external power amplifier, we can accurately remind the target person. At the same time, the development board parses the PIXHAWK flight control in real time through the MAVSDK and issues movement instructions. A highlight of the project is that it can determine whether to automatically return for wireless charging based on the real-time power. When the power is lower than the threshold, our UAV will automatically return and automatically recognize the apron to land on. After landing, it will be charged through the built-in wireless charging module, and there is no need for personnel during the whole process. If necessary, users can remotely control it through the 4G-LTE network, quickly adjust the aircraft status and obtain real-time information on the ground station UI interface.  

Besides reducing the cost of manpower management, this intelligent identification aircraft can effectively identify behaviors that are not conducive to epidemic control without interfering in the normal activities of the people in public places, and give reminders to target groups in order to maintain the health and safety of the general public.

## Key words

OpenVINO, CNN, Image Recognition, Feature Extraction, Speech Synthesis, Automation, 4G-LTE

## Main Features

* Automatic Patrol; 
* Real-time Control;
* AI Recognition; 
* Unattended; 
* Precise Propaganda; 
* Image Synchronization

## Rongyu Jiang
### Hardware Design
<img src = "https://user-images.githubusercontent.com/43924016/130093526-ec845722-6b68-4726-83a6-1730441658b9.png" width = "500">

### Open Vino Speed Up
<img src = "https://user-images.githubusercontent.com/43924016/130093704-41094516-6e2a-468b-8328-0e029362068d.png" width = "500">


## Yingli Chen

### Mask Detection

<img src = "https://user-images.githubusercontent.com/43924016/130090394-a070bf1c-7b8c-4de1-bb5c-caa9db7be2b9.png" width = "500">

Mask Recognition Module.   

SSD network: one stage, lightweight, fast.   

Precision: 0.896 for face with mask, 0.919 for face without mask.  

<img src = "https://user-images.githubusercontent.com/43924016/130090895-cd6064f9-c7c8-4460-aaf6-c4d903edc663.png" width = "400" >

<img src = "https://user-images.githubusercontent.com/43924016/130090930-a2d308fe-8f8e-4dc1-a6da-e35e69862c7f.png" width = "550">


### Face Feature Extraction
<img src = "https://user-images.githubusercontent.com/43924016/130090622-2c20522b-4fd3-4a14-9f45-c37d043e11c8.png" width = "400">

SSR-Net: multiclass problem.   

**MegaAge-Asian dataset:**.  

Containing 40,000 face images of Asians with ages from 0 to 70.  

  <p align="center">
    <img src="https://user-images.githubusercontent.com/43924016/130091056-34660be4-dcfa-4159-a57c-d0143d4bbf41.png" width="800">
  </p>

## Xingyu Tong

### Visual Landing

Used a marker to assit in landing. 

  <p align="center">
    <img src="https://user-images.githubusercontent.com/43924016/130094080-75cae242-ae29-4eb3-ad56-0ead48999a02.png" width="200">
  </p>

