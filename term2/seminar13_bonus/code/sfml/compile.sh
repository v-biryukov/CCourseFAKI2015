export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/workspace/latex/cs_mipt_faki/term2/seminar13_bonus/code/sfml/SFML-2.4.2/lib/
g++-4.8 ./balls.cpp -std=c++11 -I SFML-2.4.2/include/ -L SFML-2.4.2/lib/ -lsfml-graphics -lsfml-window -lsfml-system
