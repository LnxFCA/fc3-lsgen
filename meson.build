project(
  'fc3-lsgen',
  'c',
  license: 'GPL-3.0-or-later',
  default_options: ['buildtype=debugoptimized',
                    'warning_level=2'],
  version: '1.0.0'
)

deps = [dependency('libgcrypt', version: '>=1.8'),
        dependency('libxml-2.0', version: '>=2.9'),
        dependency('glib-2.0', version: '>=2.60')]

PROGVERSION=meson.project_version()
PROGNAME=meson.project_name()

conf_data = configuration_data()
conf_data.set_quoted('VERSION', PROGVERSION)
conf_data.set_quoted('PROGNAME', PROGNAME)

subdir('src')
