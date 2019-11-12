#pragma once

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 780

#define SPLASH_STATE_SHOW_TIME 3.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Splash Background.png"

#define MAIN_MENU_BACKGROUND_FILEPATH "Sky.png"
#define GAME_BACKGROUND_FILEPATH "Sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Sky.png"


#define GAME_TITLE_FILEPATH "title.png"
#define PLAY_BUTTON_FILEPATH "PlayButton.png"

#define PIPE_UP_FILEPATH "Pipe.png"
#define PIPE_DOWN_FILEPATH "Pipe.png"
#define SCORING_PIPE_FILEPATH "InvisibleScoringPipe.png"


#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 2.0f

#define TOBY_FRAME_1_FILEPATH "toby-01.png"
#define TOBY_FRAME_2_FILEPATH "toby-02.png"
#define TOBY_FRAME_3_FILEPATH "toby-03.png"

#define TOBY_ANIMATION_DURATION 0.4f

#define TOBY_STATE_STILL 1
#define TOBY_STATE_FALLING 2
#define TOBY_STATE_FLYING 3

#define GRAVITY 250.0f
#define FLYING_SPEED 300.0f

#define FLYING_DURATION 0.30f



enum GameStates{
	eReady,
	ePlaying,
	eGameOver
};


