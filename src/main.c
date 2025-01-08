
#include <gio/gio.h>
#include <glib-object.h>
#include <glib.h>
#include <gtk/gtk.h>
#include <stdio.h>

static void create_main_window(GtkApplication *app);
static void create_mixer_window(GtkApplication *app);

static int on_command_line(GApplication *application,
                           GApplicationCommandLine *command_line,
                           gpointer user_data) {
  int argc;
  char **argv = g_application_command_line_get_arguments(command_line, &argc);

  if (argc == 1) {
    create_main_window(GTK_APPLICATION(application));
  } else if (argc == 2 && g_strcmp0(argv[1], "--mixer") == 0) {
    create_mixer_window(GTK_APPLICATION(application));
  } else {
    g_printerr("Invalid argument.\nUsage: %s [--mixer]\n", argv[0]);
    return 1;
  }

  return 0;
}

static void activate(GtkApplication *app, gpointer user_data) {
  create_main_window(app);
}

int main(int argc, char *argv[]) {
  GtkApplication *app = gtk_application_new("dev.consti.sonar",
                                            G_APPLICATION_HANDLES_COMMAND_LINE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  g_signal_connect(app, "command-line", G_CALLBACK(on_command_line), NULL);

  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}

static void create_main_window(GtkApplication *app) {
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Sonar");
  gtk_widget_set_visible(window, TRUE);

  g_print("Main Window\n");
}

static void create_mixer_window(GtkApplication *app) {
  GtkWidget *window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Sonar Volume Mixer");
  gtk_widget_set_visible(window, TRUE);

  g_print("Mixer Window\n");
}
