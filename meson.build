project('sonar', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c11'])


gtk = dependency('gtk4')


sources = [
    'src/main.c',
    'src/app.c',
    'src/mixer/mixer.c',
    'src/mixer/mixer_ui.c',
    'src/normal/normal.c',
    'src/normal/normal_ui.c',
    'src/utils/audio.c',
    'src/utils/config.c',
    'src/utils/logger.c',
]

sonar = executable('sonar', sources, dependencies: gtk)


run_target('run',
  command: [sonar]
)

