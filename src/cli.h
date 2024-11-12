#pragma once

typedef struct {
  char *gamecfg_path;
  char *username;
  int write_lockstring;
} ProgramOptions;

ProgramOptions*   get_program_options(int *argc, char ***argv);
