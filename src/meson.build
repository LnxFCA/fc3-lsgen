configure_file(output: 'config.h',
               configuration: conf_data)

src_files = [
  'main.c',
  'cli.c'
]

executable(PROGNAME,
           src_files,
           dependencies: deps,
           install: true)
