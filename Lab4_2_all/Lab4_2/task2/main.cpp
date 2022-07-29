#include "../lib/display.h"
#ifndef __SRC_FILE
#define __SRC_FILE
#endif  // !__SRC_FILE
#include <vector>
#include <random>
#include <typeinfo>

#include "../game/border.h"
#include "../game/movingRectangle.h"
#include "../game/rectangle.h"
#include "../lib/audio.h"
#include "bird.h"

#define Vol 20
#define speed_to_create 50

using std::vector;
using ObjPool = vector<Object*>;

void detect_collision(ObjPool& pool) {
    // TODO: detect collision between each pair of objects
    /* Your code here */
    // for(vector<Object*>::iterator it1 = pool.begin(); it1 != pool.end(); it1++){
    //     //Detect Border
    //     if(typeid(**it1) == typeid(Border)){
    //         for(vector<Object*>::iterator it2 = pool.begin(); it2 != pool.end(); it2++){
    //             if(it2 == it1){
    //                 continue;
    //             }else{
    //                 (**it2).detect_collide(**it1);
    //             }
    //         }
    //     }
    //     if(typeid(**it1) == typeid(Bird)){
    //         for(vector<Object*>::iterator it2 = pool.begin(); it2 != pool.end(); it2++){
    //             if(typeid(**it2) == typeid(Border)){
    //                 continue;
    //             }else if(typeid(**it2) == typeid(Bird)){
    //                 continue;
    //             }else{
    //                 (**it1).detect_collide(**it2);
    //             }
    //         }
    //     }
    // }

    for(vector<Object*>::iterator it1 = pool.begin(); it1 != pool.end(); it1++){
        for(vector<Object*>::iterator it2 = pool.begin(); it2 != pool.end(); it2++){
                if(it2 == it1){
                    continue;
                }else{
                    (**it2).detect_collide(**it1);
                }
            }
    }
}

void show_game_over(Display& display, double second) {
    display.clear();
    display.put_string(display.get_cols() / 2 - 7, display.get_rows() / 2 - 1,
                       "Game Over");
    display.put_string(display.get_cols() / 2 - 14, display.get_rows() / 2,
                       "Bird survives " + std::to_string(second) + " seconds");
    display.put_string(display.get_cols() / 2 - 13, display.get_rows() / 2 + 1,
                       "Press any key to exit");
    display.refresh();
    display.get_char();
}

void add_rectangle(ObjPool& pool, Display& d) {
    // TODO: add a moving_rectangle to the pool
    /* Your code here */
    int width = rand()%5 + 1;
    int limit_height = (int)(0.66 * d.get_rows());
    int height = rand()%limit_height +1;
    MovingRectangle* Mov_Rec = new MovingRectangle(d.get_cols() - 1 - width,rand()%(int)(0.33*d.get_rows())+1,width,height,-1,0);
    pool.emplace_back(Mov_Rec);
}

int main() {
    Display d("log.txt");
    string audio_dir = "../audio/";
    ObjPool obj_pool;
    Bird* bird = new Bird(d.get_cols() / 2, d.get_rows() / 2, 0, 0, 0, 0);
    Border* border = new Border(0, 0, d.get_cols(), d.get_rows());
    obj_pool.emplace_back(bird);
    obj_pool.emplace_back(border);

    int count = 0;
    bool  flag_for_flap = false;

    //suppot for music
    string bgm_file = audio_dir + "bgm.mp3";
    Audio audio_bgm(bgm_file,false,Vol);
    audio_bgm.play_loop();

    string flap_file = audio_dir + "flap.mp3";
    Audio audio_flap(flap_file,false,Vol);

    string collode_file = audio_dir + "collide.mp3";
    Audio audio_collide(collode_file,false,Vol);

    string end_file = audio_dir + "applause.mp3";
    Audio audio_end(end_file,false,Vol);
    while (true) {
        // Process keyboard input
        int c = d.get_char(50);
        d.clear();
        if (c == 'q') {
            break;
        } 
        else if(c == 'z' || c == 'x'){
            flag_for_flap = false;
        }
        else if (c == ' ') {
            if(flag_for_flap == false){
                audio_flap.play_once();
            }
            flag_for_flap = true;
        }

        // Add new rectangle
        count++;
        if(count%speed_to_create == 0){
            count++;
            add_rectangle(obj_pool, d);
        }

        // Update object state
        for (auto& obj : obj_pool) {
            obj->tick(c);
        }
        
        //(*bird).tick(c);
        // Detect collision
         detect_collision(obj_pool);

        //TODO: Process invalid object
        /* Your code here */
        
        //TODO: Bird collide with border
        /* Your code here */
        for(vector<Object*>::iterator it1 = obj_pool.begin(); it1 != obj_pool.end(); it1++){
            if(typeid(**it1) == typeid(MovingRectangle)){
                if(!((**it1).get_valid())){
                    delete (*it1);
                    obj_pool.erase(it1);
                }
            }
        }

        if(!bird->get_valid()){
            audio_collide.play_once();
            break;
        }

        // Draw objects
        for (auto& obj : obj_pool) {
            obj->draw(d);
        }
        //(*bird).draw(d);

        d.put_string(1, 1, "Time: " + std::to_string(d.time() / 1000.0));
        d.put_string(1, 2, "Keystrock: " + std::to_string(c));
        d.refresh();
        d.log();
    }
    audio_bgm.stop();
    audio_end.play_once();
    show_game_over(d,d.time()/1000.0);
    return 0;
}