# CHICKEN INVADER
**NGUYỄN THỊ THANH HUYỀN**

**MSSV: 20020420**
* **Chicken Invader** 

Game với đối tượng chính là máy bay, có nhiệm vụ bắn trúng gà, nhận quà để ghi điểm và tránh trứng để duy trì mạng sống (được viết bằng ngôn ngữ C++ và sử dụng các thư viện hỗ trợ của SDL).
![](https://i.imgur.com/eWR14wm.png)
![](https://i.imgur.com/1VGEboL.png)


Video Demo Game: [link](https://drive.google.com/file/d/15Vdd2DIdN8eru0GCfBvXQLSiFG-3EHrN/view?usp=sharing)
* **Cài đặt**

 Download các thư viện hỗ trợ:
 1. SDL: [link](https://www.libsdl.org/)
 2. SDL_image: [link](https://www.libsdl.org/projects/SDL_image/)
 3. SDL_ttf: [link](https://www.libsdl.org/projects/SDL_ttf/)
 4. SDL_mixer: [link](https://www.libsdl.org/projects/SDL_mixer/)
 5. Source code: [link](https://github.com/huyen2002/CHICKEN-INVADER.git)
 * **Function**
1.  main.cpp : hàm chính
2.  HeadFunc: hàm khởi tạo chung
3.  BaseObject: hàm đối tượng chung
4.  PlaneObject: hàm của đối tượng máy bay
5.  ChickenObject: hàm của đối tượng gà và quà
6.  BulletObject: hàm của đối tượng đạn bắn
7.  TextObject: hàm của đối tượng text
8.  MenuObject: hàm xây dựng Menu Game
* **Hướng dẫn**

Nhấn PLAY để bắt đầu chơi lần đầu tiên.

Di chuyển máy bay bằng các phím lên, xuống, trái, phải, nhấn Enter để bắn đạn. Dùng chuột trái ấn vào biểu tượng dừng màn hình để dừng hoặc tiếp tục chơi. Mỗi lần bắn trúng gà được cộng 1 điểm. Mỗi lần nhận quà được cộng 5 điểm và tăng tốc độ máy bay. Khi va chạm với gà hoặc trứng, máy bay bị giảm tốc độ và mạng sống.

Khi trò chơi kết thúc, chọn PLAY AGAIN nếu muốn chơi lượt mới hoặc EXIT để thoát trò chơi.
