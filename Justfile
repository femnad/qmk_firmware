default:
    @just --choose

fetch:
    #!/usr/bin/env bash
    set -euo pipefail
    for dir in preonic keebio/nyquist_lm
    do
        git submodule update --remote keyboards/${dir}/keymaps/foolmap
        git add keyboards/${dir}/keymaps/foolmap
        if git commit -m "fetch submodule keyboards/${dir}/keymaps/foolmap"
        then
          git push
        fi
    done
