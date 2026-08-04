import threading
import time

def chef(name,dish,cook_time):
    for step in range(1,4):
        print(f"厨子：{name} 正在做{dish} 的 {step} 环节")
        time.sleep(cook_time)
    print(f"{name}:{dish}出国")

wang = threading.Thread(target=chef,args=("王伟","牛肉哇",0.5))
li = threading.Thread(target=chef, args=("李大厨", "番茄炒蛋", 0.3))

wang.start()   # 点火
li.start()     # 点火

wang.join()    # 站着等王大厨做完
li.join()      # 站着等李大厨做完

print("🎉 两道菜都上桌了！")