struct RuckSackBundle {
    // the directory to do all path searches relative to
    const char *cwd;

};

enum RuckSackAnchor {
    RuckSackAnchorCenter,
    RuckSackAnchorExplicit,

    RuckSackAnchorLeft,
    RuckSackAnchorRight,
    RuckSackAnchorTop,
    RuckSackAnchorBottom,

    RuckSackAnchorTopLeft,
    RuckSackAnchorTopRight,
    RuckSackAnchorBottomLeft,
    RuckSackAnchorBottomRight,
};

struct RuckSackImage {
    char *path;
    enum RuckSackAnchor anchor;
    int anchor_x;
    int anchor_y;

    unsigned int width;
    unsigned int height;
    // triangle strip
    int uv_coords[10];
};

// a page contains multiple images. also known as texture or spritesheet
struct RuckSackPage {
    int max_width;
    int max_height;
    // whether powers of 2 are required
    char pow2;
};

void rucksack_init(void);
void rucksack_finish(void);

struct RuckSackBundle *rucksack_bundle_open(const char *bundle_path);
void rucksack_bundle_close(struct RuckSackBundle *bundle);

struct RuckSackPage *rucksack_page_create(void);
void rucksack_page_destroy(struct RuckSackPage *page);

int rucksack_bundle_add_page(struct RuckSackBundle *bundle, const char *key,
        struct RuckSackPage *page);
void rucksack_bundle_add_file(struct RuckSackBundle *bundle, const char *key,
        const char *file_name);
void rucksack_bundle_del(struct RuckSackBundle *bundle, const char *key);

int rucksack_page_add_image(struct RuckSackPage *page, const char *key,
        struct RuckSackImage *image);

int rucksack_bundle_get_file_size(struct RuckSackBundle *bundle, const char *key);
void rucksack_bundle_get_file(struct RuckSackBundle *bundle, const char *key,
        unsigned char *buffer);

void rucksack_bundle_get_page(struct RuckSackBundle *bundle, const char *key,
        struct RuckSackPage *page);
void rucksack_page_get_image(struct RuckSackPage *page, const char *key,
        struct RuckSackImage *image);