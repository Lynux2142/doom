/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:51:58 by lguiller          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/11/23 14:46:31 by cmace            ###   ########.fr       */
=======
/*   Updated: 2018/11/23 14:27:29 by lguiller         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "libft.h"
# include "libvect.h"
# include "mlx.h"
# include "SDL.h"
# include "SDL_mixer.h"
# include <math.h>
# include <limits.h>
# include <pthread.h>

# define MAPX			32
# define MAPY			MAPX
# define INFOX			(WINY / 4)
# define INFOY			(WINY / 4)
# define BARX			(int)((double)WINX / 1.4)
# define BARY			(WINY - 45)
# define BARW			250
# define BARH			15
# define TEXT_NORTH		"./srcs/game/textures/wood1.xpm"
# define TEXT_SOUTH		"./srcs/game/textures/stone1.xpm"
# define TEXT_EAST		"./srcs/game/textures/metal1.xpm"
# define TEXT_WEST		"./srcs/game/textures/ice1.xpm"
# define TEXT_DOOR		"./srcs/game/textures/door.xpm"
# define TEXT_DOOR_R	"./srcs/game/textures/door_reverse.xpm"
# define SPR_WALK		"./srcs/game/sprites/Walk_Sprite2.xpm"
# define SPR_JUMP		"./srcs/game/sprites/Jump_Sprite2.xpm"
# define SPR_CROUCH		"./srcs/game/sprites/Crouch_Sprite2.xpm"
# define SPR_IDLE		"./srcs/game/sprites/Idle_Sprite2.xpm"
# define SPR_RUN		"./srcs/game/sprites/Run_Sprite2.xpm"
# define END_IMG		"./srcs/game/images/End_img.xpm"
# define WINX			960
# define WINY			540
# define BLOCK_SIZE		64.0
# define CAM_HEIGHT		BLOCK_SIZE / 2.0
# define FOV			60.0
# define RAY_ANGLE		FOV / (double)WINX
# define START			's'
# define END			'e'
# define FLOOR			' '
# define TP_S			'3'
# define TP_E			'4'
# define T_A			'A'
# define T_A_S			'a'
# define T_B			'B'
# define T_B_S			'b'
# define T_C			'C'
# define T_C_S			'c'
# define T_D			'D'
# define T_D_S			'd'
# define T_DOOR_C		'-'
# define T_DOOR_M		'~'
# define T_DOOR_O		'|'
# define ALPHA			0xFF000000
# define GREEN_A		0x5517EE01
# define BLACK			0
# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define GREEN			0xFF00
# define BLUE			0x0061ff
# define LIGHT_BLUE		ALPHA
# define LIGHT_GREEN	0xAAFFAA
# define GREY			0x888888
# define GREY_A			0x44888888
# define YELLOW			0xFFFF00
# define TOP			0x87CEFA
# define BOTTOM			0xFFDA8C
# define N_W			0x940602
# define S_W			0x50468C
# define E_W			0x769600
# define W_W			0xD45E3A
# define NORTH			M_PI / 2.0
# define SOUTH			3.0 * M_PI / 2.0
# define WEST			M_PI
# define EAST			0.0
# define EAST2			2.0 * M_PI
# define HIT_BOX		5.0
# define VIEW_DIST		20.0
# define TRANS_F		10
# define ZOOM			(((double)MAPX * BLOCK_SIZE / 4.0) / (double)INFOX)
# define P_SIZE			2.5
# define LITTLE			0.00000000000012
# define TRUE			1
# define FALSE			0
# define THREAD			80
# define F_MUSIC		"srcs/game/musics/"
# define F_SOUNDS		"srcs/game/sounds/"
# define M_WOAH			F_MUSIC"WOAH.wav"
# define S_OPENDOOR		F_SOUNDS"door_open.wav"
# define S_TELEPORT		F_SOUNDS"teleport.wav"
# define STAMINA_MAX	100.0

# ifdef __linux__
#  define MOVE_SPEED	2.0
#  define RUN_SPEED		3.0
#  define JUMP_SPEED	0.1
#  define CROUCH_SPEED	1.0
#  define ROT_SPEED		1.0
#  define ESC			65307
#  define KEY_A			97
#  define KEY_D			100
#  define KEY_W			119
#  define KEY_S			115
#  define KEY_H			104
#  define KEY_Q			113
#  define KEY_E			101
#  define KEY_F			102
#  define KEY_T			116
#  define KEY_L			37
#  define KEY_SPACEBAR	32
#  define KEY_CTRL		256
#  define KEY_ENTER		36
#  define KEY_SHIFT		65505
#  define KEYS_TAB_SIZE	65600
# else
#  define MOVE_SPEED	2.0
#  define RUN_SPEED		5.0
#  define JUMP_SPEED	0.1
#  define CROUCH_SPEED	1.0
#  define ROT_SPEED		2.0
#  define ESC			53
#  define KEY_A			0
#  define KEY_D			2
#  define KEY_W			13
#  define KEY_S			1
#  define KEY_H			4
#  define KEY_Q			12
#  define KEY_E			14
#  define KEY_F			3
#  define KEY_T			17
#  define KEY_L			37
#  define KEY_SPACEBAR  49
#  define KEY_CTRL		256
#  define KEY_ENTER		36
#  define KEY_SHIFT		257
#  define KEYS_TAB_SIZE	280
# endif

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_fcoord
{
	double		x;
	double		y;
}				t_fcoord;

typedef struct	s_player
{
	int			ray_infos;
	double		x;
	double		y;
	double		a;
}				t_player;

typedef struct	s_parse
{
	char		*buff;
	char		fd;
	short		i;
}				t_parse;

typedef struct	s_ray
{
	double		dist;
	int			hit;
	double		fx;
	double		fy;
	double		xa;
	double		ya;
	double		dx;
	double		dy;
	double		x;
	double		y;
}				t_ray;

typedef struct	s_raycast
{
	char		map[MAPY][MAPX];
	t_ray		ray_h;
	t_ray		ray_v;
	t_ray		ray;
}				t_raycast;

typedef struct	s_img
{
	int			endian;
	char		*data;
	void		*img;
	int			bpp;
	int			sl;
	int			width;
	int			height;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_img		info;
	t_img		fp;
}				t_mlx;

typedef struct	s_algo_brez
{
	int			cumul;
	int			cpta;
	int			cptb;
	int			da;
	int			db;
	int			i;
	int			a;
	int			b;
}				t_algo_brez;

typedef struct	s_textures
{
	int			height;
	int			width;
	t_img		img_w;
	t_img		img_e;
	t_img		img_n;
	t_img		img_s;
	t_img		img_d;
	t_img		img_dr;
}				t_textures;

typedef struct	s_sprites
{
	void		*ptr;
	int			height;
	int			width;
}				t_sprites;

<<<<<<< HEAD
typedef struct	s_musics
{
	Mix_Music	*musics;
}				t_musics;

typedef struct	s_sounds
{
	Mix_Chunk	*opendoor;
	Mix_Chunk	*teleport;
}				t_sounds;
=======
typedef struct	s_hud
{
	t_sprites	s_jump;
	t_sprites	s_run;
	t_sprites	s_idle;
	t_sprites	s_walk;
	t_sprites	s_crouch;
	t_img		stamina_bar;
}				t_hud;
>>>>>>> master

typedef struct	s_all
{
	int			keys_tab[KEYS_TAB_SIZE];
	t_musics	musics;
	t_sounds	sounds;
	t_textures	textures;
	t_hud		hud;
	t_img		info;
	t_img		map;
	t_img		end_img;
	t_mlx		ptr;
	t_img		fp;
	t_raycast	rc;
	t_player	p;
	double		a;
	int			i;
	double		lens;
	int			x;
	int			prevx;
	int			prevy;
	int			start_wall;
	int			skip;
	double		wall_gap;
	double		speed;
	int			s_jump;
	int			jump;
	int			s_idle;
	int			stamina;
	int			end;
}				t_all;

void			*ft_wall_dist(void *ptr);
void			ft_print_ray_infos(t_all *all);
void			ft_algo(t_img *ptr, t_point p1, t_point p2, int col);
int				ft_button_press(int key, int x, int y, t_all *all);
void			ft_init_player(char map[MAPY][MAPX], t_player *p);
void			ft_read_file(char *name, char (*map)[MAPY][MAPX]);
void			ft_init_keys_tab(int (*keys_tab)[KEYS_TAB_SIZE]);
void			ft_fill_pixel(t_img *ptr, int x, int y, int col);
void			ft_print_on_screen(t_all *all, int x, double a);
void			ft_print_map(t_img *ptr, char map[MAPY][MAPX], t_player p);
void			ft_perso(t_img *img, t_player p);
void			ft_init_mlx(t_all *all, char *title);
int				ft_key_release(int key, t_all *all);
void			ft_free_map(char map[MAPY][MAPX]);
int				ft_key_press(int key, t_all *all);
void			ft_draw(t_all all, char *name);
void			ft_print_all(t_all *all);
int				ft_movements(t_all *all);
int				ft_quit(void);
void			ft_cpy_struct(t_all *tmp, t_all *all);
int				ft_mouse_motion(int x, int y, t_all *all);
int				to_map(double x);
int				to_win(int x);
int				is_wall(char wall);
int				is_door(char map[MAPY][MAPX], t_ray *ray);
int				is_displayable(char c);
void			jump_and_crouch(t_all *all);
void			open_door(t_all *all);
float			timer(float add, int x, int y, char c);
void			ft_fp_hori(t_ray *ray, t_player *p, char map[MAPY][MAPX],
		double a);
void			ft_fp_vert(t_ray *ray, t_player *p, char map[MAPY][MAPX],
		double a);
int				ft_wall_height_on_screen(double dist);
<<<<<<< HEAD
void			ft_init_sdl(t_all *all);
void			init_sounds(t_all *all);
=======
void			init_stickman(t_all *all);
int				is_movement(int keys_tab[KEYS_TAB_SIZE]);
void			init_image(t_mlx ptr, t_img *img, int x, int y);
void			print_stamina_bar(t_img *img, int stamina);
void			stamina_control(t_all *all);
void			refresh_events(t_all *all);
void			ft_moving(t_all *all, double dir);
void			ft_strafing(t_all *all, double dir);
void			scale_img(t_img *dst, t_img *src);
>>>>>>> master

#endif