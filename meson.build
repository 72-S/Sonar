project('sonar', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c11'])

sonar = executable('sonar', 'main.c', install : true)

test('test', sonar)