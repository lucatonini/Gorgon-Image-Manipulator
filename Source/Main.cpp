#include <Gorgon/Main.h>
#include <Gorgon/Window.h>
#include <Gorgon/WindowManager.h>
#include <Gorgon/Graphics/Layer.h>
#include <Gorgon/Graphics/FreeType.h>
#include <Gorgon/Graphics/BlankImage.h>
#include <Gorgon/Input/Keyboard.h>
#include <Gorgon/Widgets/Button.h>
#include <Gorgon/Widgets/RadioButtons.h>
#include <Gorgon/UI/Component.h>
#include <Gorgon/String.h>
#include <Gorgon/UI/Window.h>
#include <Gorgon/Widgets/Panel.h>
#include <math.h>
#include <iostream>


class Image{
public:
    Image(std::string imageName){
        img.Import(imageName);
        imgSize = img.GetSize();
    }
    
    Image( Image & img2){
        img = img2.img.Duplicate();
        imgSize = img2.imgSize;
    }
    
    Image(int x, int y){
        imgSize.Width = x;
        imgSize.Height = y;
        img.Resize(imgSize);
    }
    
    void nearestNeighbor(Image oldImg){
        float scalefy = (float)oldImg.imageHeight() / imgSize.Height ;
        float scalefx = (float)oldImg.imageWidth() / imgSize.Width;
        
        for(int y = 0 ; y < imgSize.Height; y++){
            for(int x = 0 ; x < imgSize.Width; x++){
                img.SetRGBAAt(x,y,oldImg.img.GetRGBAAt({x * scalefx, y * scalefy}));
            }
        }
    }
    
    void biLinearIntepolation(Image oldImg){
        
        float sfx = (float) oldImg.imageWidth() / imgSize.Width;
        float sfy = (float) oldImg.imageHeight() / imgSize.Height;
        
        for(int y = 0 ; y < imgSize.Height; y++){
            for(int x = 0 ; x < imgSize.Width; x++){
                
                Gorgon::Graphics::RGBA newPxl;
                float cx,cy,rx,ry,t1,t2,t3,t4;
                
                //This will find the pixle that we will be using to make the new image
                cx = x *sfx;
                cy = y *sfy;
                
                //This will find the weight between the 2 x and y points respectfily
                rx = cx - floor(cx);
                ry = cy - floor(cy);
                
                //Calculate the Red element of the pixel
                t1 = oldImg.img.GetRGBAAt({cx,cy}).R * (1-rx)*(1-ry);
                t2 = oldImg.img.GetRGBAAt({cx+1,cy}).R * rx * (1-ry);
                t3 = oldImg.img.GetRGBAAt({cx,cy+1}).R * (1-rx) * ry;
                t4 = oldImg.img.GetRGBAAt({cx,cy+1}).R * rx * ry;
                newPxl.R =  round(t1+t2+t3+t4);
                
                //Calculate the Green element of the pixel
                t1 = oldImg.img.GetRGBAAt({cx,cy}).G * (1-rx)*(1-ry);
                t2 = oldImg.img.GetRGBAAt({cx+1,cy}).G * rx * (1-ry);
                t3 = oldImg.img.GetRGBAAt({cx,cy+1}).G * (1-rx) * ry;
                t4 = oldImg.img.GetRGBAAt({cx,cy+1}).G * rx * ry;
                newPxl.G =  round(t1+t2+t3+t4);
                
                //Calculate the Blue element of the pixel
                t1 = oldImg.img.GetRGBAAt({cx,cy}).B * (1-rx)*(1-ry);
                t2 = oldImg.img.GetRGBAAt({cx+1,cy}).B * rx * (1-ry);
                t3 = oldImg.img.GetRGBAAt({cx,cy+1}).B * (1-rx) * ry;
                t4 = oldImg.img.GetRGBAAt({cx,cy+1}).B * rx * ry;
                newPxl.B =  round(t1+t2+t3+t4);
                
                newPxl.A = 255;
                
                //Assign the new pixel to our image
                img.SetRGBAAt(x,y,newPxl);
                
            }
        }
        
    }
    
    void saveImage(std::string newName){
        img.ExportPNG(newName);
    }
    
    int imageWidth(){
        return imgSize.Width;
    }
    
    int imageHeight(){
        return imgSize.Height;
    }
    
    Gorgon::Graphics::Bitmap img;
private:
    
    Gorgon::Geometry::Size imgSize;
};

int main() {
    
    //Initialize
    Gorgon::Initialize("ImageManipulator");
    
    //Window
    Gorgon::UI::Window window({700, 800}, "Gorgon Image Manipulator");
    
    //Gorgon Icon
    Gorgon::Graphics::Bitmap icon;
    icon.Import("Icon.png");

    //Show the icon as window icon
    Gorgon::WindowManager::Icon ico(icon.GetData());
    window.SetIcon(ico);
    
    //Load a font to display some text
    Gorgon::Graphics::FreeType font, smallfont;
    
    //Microsoft Windows fonts
    
    
#ifdef WIN32
    font.LoadFile(Gorgon::OS::GetEnvVar("windir")+"/Fonts/tahoma.ttf", 20);
    smallfont.LoadFile(Gorgon::OS::GetEnvVar("windir")+"/Fonts/tahoma.ttf", 11);
#else
    font.LoadFile("/usr/share/fonts/liberation/LiberationSerif-Regular.ttf", 20);
    smallfont.LoadFile("/usr/share/fonts/liberation/LiberationSerif-Regular.ttf", 11);
#endif
    
    //Create a layer to draw on
    Gorgon::Graphics::Layer dragAndDropLayer, settingsLayer, backgroundLayer;
    window.Add(backgroundLayer);
    
    Gorgon::Graphics::BlankImage bg(0.1f);
    
    //Draw in layer, filling it
    bg.DrawIn(backgroundLayer);
    font.Print(backgroundLayer, "Drag and drop Image here!",0, 10, 700, Gorgon::Graphics::TextAlignment::Center);
    smallfont.Print(backgroundLayer, "Press ESC to exit", 5, 800 - smallfont.GetHeight() - 5, Gorgon::Graphics::RGBAf(1.0, 0.6, 0.4));
    
    //SettingsLayer
    settingsLayer.SetColor(Gorgon::Graphics::RGBAf(1.0, 0.6, 0.4));
    settingsLayer.Resize(600,200);
    settingsLayer.SetTintColor(Gorgon::Graphics::RGBAf(0.5, 0.6, 0.4));
    settingsLayer.Move(50,550);
    
    
    Image img("read.jpg");
    
    Image newImg(340,340);
    newImg.nearestNeighbor(img);
    newImg.saveImage("NearestNeighbor.png");
    
    Image bilinImg(340,340);
    bilinImg.biLinearIntepolation(img);
    bilinImg.saveImage("Bilinear.png");
    
    //img.Prepare();
    //img.img.Draw(dragAndDropLayer,Gorgon::Geometry::Point(100,100),Gorgon::Graphics::RGBAf(0.8,1.0,1.0));
    font.Print(backgroundLayer, "Image size: " + std::to_string(img.imageWidth()) + "x" + std::to_string(img.imageHeight()) ,0, 100, 700, Gorgon::Graphics::TextAlignment::Center);
    
    
    
    window.KeyEvent.Register([&](Gorgon::Input::Key key, float state) {
        namespace Keycodes = Gorgon::Input::Keyboard::Keycodes;
        
        //if S key is pressed,
        if(key == Keycodes::S  && state == 1) {
        
            //img.saveImage("NewImage.jpg");
        }
        
        //if esc is pressed
        if(key == Keycodes::Escape && state == 1) {
            //exit
            
            exit(0);
        }
        
        //we gobble all keys
        return true;
    });
    
    //Terminate the application when the window is closed
    window.DestroyedEvent.Register([&]() {
        exit(0);
    });
    
    //until we call quit
    while(true) {
        Gorgon::NextFrame();
    }
    
    return 0;
}
