#ifndef CUB3D_PARSING_H
#define CUB3D_PARSING_H

bool parse_environement_texture(t_game_engine *engine, char *descriptor, char *content);
bool parse_environement_color(t_game_engine *engine, char *descriptor, char *content);
bool parse_resolution(char *descriptor, char *content, t_vector2 *resolution);
void parse_game_engine(t_game_engine *engine, int fd, t_vector2 *resolution);
bool parse_map_line(t_game_engine *engine, char *line, t_vector2 *map_size);
void compute_map(t_game_engine *engine, t_vector2 map_size);
void parse_map(t_game_engine *engine, int fd);

#endif
