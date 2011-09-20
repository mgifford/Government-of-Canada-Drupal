; Include Build Kit distro makefile via URL
includes[] = http://drupalcode.org/project/buildkit.git/blob_plain/refs/heads/7.x-2.x:/distro.make

; Add govcan to the full Drupal distro build
projects[govcan][type] = profile
projects[govcan][download][type] = git
projects[govcan][download][url] = git://github.com/sylus/govcan.git