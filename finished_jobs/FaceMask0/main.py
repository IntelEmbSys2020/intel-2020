import tensorflow_infer

if __name__ == "__main__":
    '''img mode'''
    # imgPath = None
    # img = cv2.imread(imgPath)
    # img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    # tensorflow_infer.inference(img, show_result=True, target_shape=(260, 260))

    '''video mode'''
    video_path = 0
    tensorflow_infer.run_on_video(video_path, '', conf_thresh=0.7)
