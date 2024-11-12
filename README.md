# fc3-lsgen

Unlocks Deluxe Edition content for Far Cry 3.

This project is based on [FC3LockStringGenerator](https://github.com/wynick27/GameRE)
which was originally written for Windows (.NET 3.1).

This program is written for Linux and can be run on:

- SteamDeck (Linux)
- Linux
- WSL (Windows Subsystem for Linux)

## Usage

```txt
fc3-lsgen [OPTIONS...]

Help Options:
  -h, --help                  Show help options

Application Options:
  -c, --gamecfg_file=FILE     Full path to GameProfile.xml
  -u, --username=STRING       Username or nickname as it appears in Ubisoft Connect
  -w, --write                 Write the generated LockString to GameProfile.xml
```

## Building

This project uses the [meson](https://mesonbuild.com/) build system, so you can
build it as any other meson project.

The project needs the following dependencies:

- glib2 >= 2.60
- libgcrypt >= 1.8
- libxml2 >= 2.9
- meson *

*NOTE: \* are buildtime dependencies only*

Build:

```sh
meson setup -Dprefix=/usr build
meson compile -C build
```

Install:

```sh
sudo meson install -C build
```

Run:

```sh
fc3-lsgen --help
```

## Building for other platforms.

While is not supported directly bu the project, the code is not OS specific so you can
build it for any other OS that supports the `meson` build system and `glib2`.
