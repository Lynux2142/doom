/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:14:15 by bede-fre          #+#    #+#             */
/*   Updated: 2018/12/10 17:52:58 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"
# include "SDL_mixer.h"
# include "libvect.h"
# include "libft.h"

# define WIN_DIM	25
# define WIN_WIDTH	WIN_HEIGHT + 18 * SCALE
# define WIN_HEIGHT	(MAP_HEIGHT + 2) * WIN_DIM
# define MAP_WIDTH	32
# define MAP_HEIGHT	32
# define SCALE		(int)((double)WIN_HEIGHT / (double)(MAP_HEIGHT + 2))
# define GAP		SCALE
# define CAP_FPS	60
# define NB_BUTTONS	19
# define START		's'
# define END		'e'
# define FLOOR		' '
# define TP_S		'1'
# define TP_E		'2'
# define T_A		'A'
# define T_B		'B'
# define T_C		'C'
# define T_D		'D'
# define T_AS		'a'
# define T_BS		'b'
# define T_CS		'c'
# define T_DS		'd'
# define BARREL		'3'
# define MOB		'4'
# define UPSTAMI	'5'
# define JETPACK	'6'
# define GIRL		'7'
# define T_DOOR		'-'
# define TRUE		1
# define FALSE		0
# define F_SOUNDS	"srcs/map_editor/sounds/"
# define F_FONT		"srcs/map_editor/font/"
# define F_TEXT		"srcs/map_editor/textures/"
# define F_IMAGE	"srcs/map_editor/images/"
# define TEXT_A		F_TEXT"wood.png"
# define TEXT_B		F_TEXT"stone.png"
# define TEXT_C		F_TEXT"metal.png"
# define TEXT_D		F_TEXT"ice.png"
# define TEXT_SA	F_TEXT"no_wood.png"
# define TEXT_SB	F_TEXT"no_stone.png"
# define TEXT_SC	F_TEXT"no_metal.png"
# define TEXT_SD	F_TEXT"no_ice.png"
# define TEXT_DOOR	F_TEXT"door.png"
# define ERASER		F_IMAGE"eraser.png"
# define TEXT_SOUND	F_IMAGE"sound.png"
# define TEXT_MUTE	F_IMAGE"soundmute.png"
# define T_BARREL	F_IMAGE"barrel.png"
# define T_JETPACK	F_IMAGE"jetpack.png"
# define T_GIRL		F_IMAGE"girl.png"
# define T_UPSTAMI	F_IMAGE"upstamina.png"
# define T_TP_START	F_TEXT"nether.png"
# define T_MOB		F_IMAGE"mob.png"
# define FONT		F_FONT"times-new-roman.ttf"
# define S_WOOD		F_SOUNDS"pose.wav"
# define S_METAL	F_SOUNDS"pose.wav"
# define S_STONE	F_SOUNDS"pose.wav"
# define S_ICE		F_SOUNDS"pose.wav"
# define S_TP_S		F_SOUNDS"pose.wav"
# define S_TP_E		F_SOUNDS"pose.wav"
# define S_DOOR		F_SOUNDS"pose.wav"
# define S_END		F_SOUNDS"pose.wav"
# define S_START	F_SOUNDS"pose.wav"
# define S_ERASER	F_SOUNDS"erase.wav"
# define S_ERROR	F_SOUNDS"error.wav"

/*
** COLOR RGBA
*/

# define BLACK		(Uint32)0x000000FF
# define BLUE		(Uint32)0x0000FFFF
# define WHITE		(Uint32)0xFFFFFFFF
# define GREY		(Uint32)0x555555FF
# define RED		(Uint32)0x990000FF
# define GREEN		(Uint32)0x009900FF
# define LIGHT_GREY	(Uint32)0xBBBBBBFF
# define YELLOW		(Uint32)0xFFFF00FF
# define ORANGE		(Uint32)0xFFA500FF
# define PURPLE		(Uint32)0x642EFEFF
# define PINK		(Uint32)0xC71585FF
# define START_COL	RED
# define T_A_COL	(Uint32)0x844927FF
# define T_B_COL	(Uint32)0xF3A16AFF
# define T_C_COL	(Uint32)0x7E878BFF
# define T_D_COL	(Uint32)0x499BC4FF
# define T_AS_COL	(Uint32)0xB87C5AFF
# define T_BS_COL	(Uint32)0xF5C19FFF
# define T_CS_COL	(Uint32)0xC0C5C8FF
# define T_DS_COL	(Uint32)0x86D1F7FF
# define SECRET_COL	(Uint32)0x888888FF
# define TP_S_COL	(Uint32)0xAAFFAAFF
# define TP_E_COL	(Uint32)0x00FF00FF
# define T_DOOR_COL	(Uint32)0x4AD8D4FF
# define END_COL	PURPLE

enum				e_keys
{
	K_RESET = 0,
	K_RENDER,
	K_QUIT,
	K_LEAKS,
	K_MUTE,
	B_LEFT,
	B_RIGHT,
	K_END
};

enum				e_button
{
	WOOD = 0,
	METAL,
	STONE,
	ICE,
	B_BARREL,
	B_JETPACK,
	B_UPSTAMI,
	B_MOB,
	B_GIRL,
	COLISION,
	NO_COLISION,
	TP_START,
	TP_END,
	B_START,
	B_DOOR,
	B_ERASER,
	B_END,
	B_SOUND,
	B_MUTE
};

typedef struct		s_parse
{
	char			*buff;
	char			fd;
	short			i;
}					t_parse;

typedef struct		s_textures
{
	SDL_Texture		*t_a;
	SDL_Texture		*t_b;
	SDL_Texture		*t_c;
	SDL_Texture		*t_d;
	SDL_Texture		*t_barrel;
	SDL_Texture		*t_jetpack;
	SDL_Texture		*t_girl;
	SDL_Texture		*t_upstami;
	SDL_Texture		*eraser;
	SDL_Texture		*door;
	SDL_Texture		*sound;
	SDL_Texture		*mute;
	SDL_Texture		*t_tp_start;
	SDL_Texture		*t_mob;
}					t_textures;

typedef struct		s_surfaces
{
	SDL_Surface		*s_a;
	SDL_Surface		*s_b;
	SDL_Surface		*s_c;
	SDL_Surface		*s_d;
	SDL_Surface		*s_sa;
	SDL_Surface		*s_sb;
	SDL_Surface		*s_sc;
	SDL_Surface		*s_sd;
	SDL_Surface		*s_barrel;
	SDL_Surface		*s_jetpack;
	SDL_Surface		*s_girl;
	SDL_Surface		*s_upstami;
	SDL_Surface		*s_eraser;
	SDL_Surface		*s_door;
	SDL_Surface		*s_sound;
	SDL_Surface		*s_mute;
	SDL_Surface		*s_tp_start;
	SDL_Surface		*s_mob;
}					t_surfaces;

typedef struct		s_button
{
	t_point			pos;
	t_point			size;
	SDL_Rect		rect;
	int				button_col;
	int				border_col;
	SDL_Surface		*surface;
}					t_button;

typedef struct		s_sounds
{
	Mix_Music		*wood;
	Mix_Music		*metal;
	Mix_Music		*stone;
	Mix_Music		*ice;
	Mix_Music		*door;
	Mix_Music		*tp_start;
	Mix_Music		*tp_exit;
	Mix_Music		*erase;
	Mix_Music		*error;
	Mix_Music		*end;
	Mix_Music		*start;
}					t_sounds;

typedef struct		s_env
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	TTF_Font		*font;
	t_sounds		sounds;
	t_surfaces		surf;
	t_textures		text;
	char			map[MAP_HEIGHT][MAP_WIDTH];
	int				*bindings;
	int				*keys;
	t_point			mouse;
	char			*file_name;
	char			object;
	int				colision;
	int				sound;
	t_button		buttons[NB_BUTTONS];
}					t_env;

void				init(t_env *env, char *file_name);
void				events(SDL_Event event, int *loop, t_env *env);
void				refresh_events(t_env *env);
SDL_Surface			*init_surface(t_env *env, int w, int h);
SDL_Texture			*create_texture(SDL_Surface *surface, t_env *env);
void				print_view(SDL_Surface *surface, t_env *env);
void				clear(t_env *env, const char *str, int error);
void				start_draw(t_env *env);
void				fill_px(SDL_Surface *surface, int x, int y, Uint32 col);
void				make_grid(SDL_Surface *surface);
void				read_file(char *name, char (*map)[MAP_HEIGHT][MAP_WIDTH]);
void				fill_rect(SDL_Surface *surface, t_point coord, Uint32 col);
void				fill_border(SDL_Surface *surface, t_point coord, int l,
						Uint32 col);
void				fill_cross(SDL_Surface *surface, t_point coord, Uint32 col);
void				print_map(SDL_Surface *surface,
						char map[MAP_HEIGHT][MAP_WIDTH], t_env *env);
int					map_to_win(int x);
int					win_to_map(int x);
void				modif_map(t_env *env);
void				write_file(char *file_name,
						char map[MAP_HEIGHT][MAP_WIDTH]);
t_point				point_to_map(t_point p);
t_point				point_to_win(t_point p);
void				key_press(SDL_Event event, t_env *env);
void				key_release(SDL_Event event, t_env *env);
void				button_press(SDL_Event event, t_env *env);
void				button_release(SDL_Event event, t_env *env);
void				print_buttons(t_env *env, SDL_Surface *surface,
						char object, int colision);
void				init_button(t_env *env);
void				set_text(SDL_Surface *surface, t_env *env);
SDL_Rect			create_rect(int x, int y, int w, int h);
SDL_Rect			rect_to_map(SDL_Rect rect);
SDL_Rect			rect_to_win(SDL_Rect rect);
int					get_object(char x);
int					get_colision(int x);
char				chose_object(t_button buttons[NB_BUTTONS], int x, int y,
						int colision);
void				create_new_file(char *file);
Mix_Music			*get_sounds(t_env *env, char x);
void				destroy_text(t_env *env);
SDL_Texture			*what_image(t_textures text, char object);
SDL_Surface			*what_surface(t_surfaces surf, char object);
int					is_image(char c);
int					is_color(char c);
void				init_textures(t_env *env);
void				init_surfaces(t_env *env);
void				scale_surface(SDL_Surface *dst, SDL_Surface *src,
						SDL_Rect *r);

#endif
