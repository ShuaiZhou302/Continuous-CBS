#include <iostream>
#include <fstream>
#include "map.h"
#include "task.h"
#include "cbs.h"
#include "xml_logger.h"

int main(int argc, const char *argv[])
{
    if(argc > 2)
    {
        Config config;
        if(argc > 3)
            config.getConfig(argv[3]);
        Map map = Map(config.agent_size, config.connectdness);
        map.get_map(argv[1]);
        Task task;
        task.get_task(argv[2]);
        if(map.is_roadmap())
            task.make_ij(map);
        else
            task.make_ids(map.get_width());
        CBS cbs;
        Solution solution = cbs.find_solution(map, task, config);
        XML_logger logger;
        auto found = solution.found?"true":"false";
        std::cout<< "Soulution found: " << found << "\nRuntime: "<<solution.time.count() << "\nMakespan: " << solution.makespan << "\nSoc: " << solution.flowtime<< "\nInitial Cost: "<<solution.init_cost<< "\nCollision Checking Time: " << solution.check_time
             << "\nHL expanded: " << solution.high_level_expanded << "\nLL searches: " << solution.low_level_expansions << "\nLL expanded(avg): " << solution.low_level_expanded << std::endl;

        logger.get_log(argv[2]);
        logger.write_to_log_summary(solution);
        logger.write_to_log_path(solution, map);
        logger.save_log();
    }
    else
    {
        std::cout<<"Error! Not enough input parameters are specified!\n";
    }
//    Config config;
//    config.getConfig("C:/Users/David Zhou/Documents/GitHub/Continuous-CBS/Examples/config.xml"); // 替换为你的配置文件路径
//    Map map = Map(config.agent_size, config.connectdness);
//    map.get_map("C:/Users/David Zhou/Documents/GitHub/Continuous-CBS/Examples/grid_map.xml"); // 替换为你的地图文件路径
//    Task task;
//    task.get_task("C:/Users/David Zhou/Documents/GitHub/Continuous-CBS/Examples/grid_task.xml"); // 替换为你的任务文件路径
//
//    if(map.is_roadmap())
//        task.make_ij(map);
//    else
//        task.make_ids(map.get_width());
//
//    CBS cbs;
//    Solution solution = cbs.find_solution(map, task, config);
//    XML_logger logger;
//    auto found = solution.found ? "true" : "false";
//    std::cout << "Solution found: " << found << "\nRuntime: " << solution.time.count()
//              << "\nMakespan: " << solution.makespan << "\nSoc: " << solution.flowtime
//              << "\nInitial Cost: " << solution.init_cost
//              << "\nCollision Checking Time: " << solution.check_time
//              << "\nHL expanded: " << solution.high_level_expanded
//              << "\nLL searches: " << solution.low_level_expansions
//              << "\nLL expanded(avg): " << solution.low_level_expanded << std::endl;
//
//    logger.get_log("C:/Users/David Zhou/Documents/GitHub/Continuous-CBS/Examples/grid_task_log.xml"); // 替换为日志文件路径
//    logger.write_to_log_summary(solution);
//    logger.write_to_log_path(solution, map);
//    logger.save_log();
    return 0;
}
