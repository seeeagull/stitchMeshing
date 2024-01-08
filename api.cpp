#include "src/common.h"
#include "src/viewer.h"
#include "src/batch.h"
#include "api.h"

/* Force usage of discrete GPU on laptops */
NANOGUI_FORCE_DISCRETE_GPU();

int runStitchMeshing(std::vector<std::vector<int>> &faces,
                     std::vector<std::vector<float>> &verts,
                     int argc, char **argv) {
    int nprocs = -1;
    std::string batchInput = "", batchOutput = "";
    bool flip = false;
	Float scale = -1;
    #if defined(__APPLE__)
        bool launched_from_finder = false;
    #endif

    try {
        for (int i=1; i<argc; ++i) {
            if (strcmp("-s", argv[i]) == 0) {
				scale = stitchMeshing::str_to_float(argv[++i]);
			} else if (strcmp("-i", argv[i]) == 0) {
				batchInput = argv[++i];
			} else if (strcmp("-o", argv[i]) == 0) {
                batchOutput = argv[++i];
			} else if (strcmp("--flip", argv[i]) == 0) {
                flip = true;
#if defined(__APPLE__)
            } else if (strncmp("-psn", argv[i], 4) == 0) {
                launched_from_finder = true;
#endif
			}  
        }
    } catch (const std::exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    tbb::task_scheduler_init init(nprocs == -1 ? tbb::task_scheduler_init::automatic : nprocs);

    try {
        stitchMeshing::batch_process(batchInput, batchOutput, scale, flip, faces, verts);
        return EXIT_SUCCESS;
    } catch (const std::exception &e) {
        cerr << "Caught runtime error : " << e.what() << endl;
        return -1;
    }
}