#include <gtk/gtk.h>
#include "include/normal/normal.h"
#include "include/mixer/mixer.h"
static int on_command_line(GApplication *application,
                           GApplicationCommandLine *command_line,
                           gpointer user_data) {
  int argc;
  char **argv = g_application_command_line_get_arguments(command_line, &argc);

  if (argc == 1) {
    normal_activate(GTK_APPLICATION(application));
  } else if (argc == 2 && g_strcmp0(argv[1], "--mixer") == 0) {
    mixer_activate(GTK_APPLICATION(application));
  } else {
    g_printerr("Invalid argument.\nUsage: %s [--mixer]\n", argv[0]);
    return 1;
  }

  return 0;
}

int main(int argc, char *argv[]) {
  GtkApplication *app = gtk_application_new("dev.consti.sonar",
                                            G_APPLICATION_HANDLES_COMMAND_LINE);
  g_signal_connect(app, "activate", G_CALLBACK(normal_activate), NULL);
  g_signal_connect(app, "command-line", G_CALLBACK(on_command_line), NULL);

  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}


