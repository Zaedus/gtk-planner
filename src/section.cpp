#include "section.hpp"

#define SECTION_PADDING 5

Section::Section(Project *project, std::string title, int position)
    : project{project}, position{position}, title{title}
{
    GtkBox *title_box;
    GtkLabel *title_label;
    GtkLabel *count_label;
    char *title_markup;

    title_box   = GTK_BOX (gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0));
    container   = GTK_BOX (gtk_box_new(GTK_ORIENTATION_VERTICAL, 0));
    title_label = GTK_LABEL (gtk_label_new(NULL));
    count_label = GTK_LABEL (gtk_label_new("0"));

    gtk_widget_set_name(GTK_WIDGET (container), "section");

    title_markup = g_markup_printf_escaped("<b>%s</b>", title.c_str());
    gtk_label_set_markup(title_label, title_markup);

    gtk_label_set_justify(title_label, GTK_JUSTIFY_LEFT);
    gtk_label_set_justify(count_label, GTK_JUSTIFY_RIGHT);

    gtk_widget_set_valign(GTK_WIDGET (container), GTK_ALIGN_START);

    // Pack

    gtk_box_pack_start(title_box, GTK_WIDGET (title_label), false, false, 0);
    gtk_box_pack_end(title_box, GTK_WIDGET (count_label), false, false, 0);

    gtk_box_pack_start(container, GTK_WIDGET (title_box), false, false, SECTION_PADDING);
    gtk_box_pack_start(container, gtk_separator_new(GTK_ORIENTATION_HORIZONTAL), false, false, SECTION_PADDING);

    gtk_flow_box_insert(project->content_container, GTK_WIDGET (container), position);
}