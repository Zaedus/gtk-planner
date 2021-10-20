#include "application.hpp"

int main(int argc, char* argv[])
{
    Glib::RefPtr<PlannerApplication> application = PlannerApplication::get();
    return application->run(argc, argv);
}