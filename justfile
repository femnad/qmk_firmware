default:
    @just --choose

fetch:
    git submodule update --remote keyboards/preonic/keymaps/foolmap
    git add keyboards/preonic/keymaps/foolmap
    git commit -m "fetch submodule keyboards/preonic/keymaps/foolmap"
    git push
