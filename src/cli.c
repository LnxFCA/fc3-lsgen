#include <glib.h>

#include "cli.h"

static ProgramOptions options;
static GOptionEntry entries[] = {
  {
    "gamecfg_file",
    'c',
    G_OPTION_FLAG_NONE,
    G_OPTION_ARG_FILENAME,
    &options.gamecfg_path,
    "Full path to GameProfile.xml",
    "FILE",
  },
  {
    "username",
    'u',
    G_OPTION_FLAG_NONE,
    G_OPTION_ARG_STRING,
    &options.username,
    "Username or nickname as it appears in Ubisoft Launcher",
    "STRING",
  },
  {
    "write",
    'w',
    G_OPTION_FLAG_REVERSE,
    G_OPTION_ARG_NONE,
    &options.username,
    "Write the generated lockstring to GameProfile.xml",
    NULL,
  },
  { 0 } 
};

ProgramOptions* get_program_options(int *argc, char ***argv) {
  GOptionContext *context;

  context = g_option_context_new(NULL);

  g_option_context_add_main_entries(context, entries, NULL);
  g_option_context_parse(context, argc, argv, NULL);

  return &options;
}
