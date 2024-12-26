project('sonar', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c11'])


gtk = dependency('gtk4')

sonar = executable('sonar', 'src/main.c', 
  dependencies : gtk)

