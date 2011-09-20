; Include Build Kit install profile makefile via URL
includes[] = http://drupalcode.org/project/buildkit.git/blob_plain/refs/heads/7.x-2.x:/drupal-org.make

;Multilingual
projects[i18n][version] = 7.x-1.0

;Workflow
projects[workbench][version] = 7.x-1.0
projects[workbench_access][version] = 7.x-1.0
projects[workbench_moderation][version] = 7.x-1.0
projects[workbench_files][version] = 7.x-1.0
projects[workbench_media][version] = 7.x-1.0

;Admin Interface
projects[admin_menu][version] = 7.x-3.0-rc1
projects[admin_select][version] = 7.x-1.1

;Search
projects[apachesolr][version] = 7.x-1.x-dev

;WYSIWYG
projects[libraries][version] = 7.x-1.0
projects[ckeditor][version] = 7.x-1.3
projects[ckeditor_link][version] = 7.x-2.0
projects[imce][version] = 7.x-1.4
projects[htmlpurifier][version] = 7.x-2.x-dev
projects[colorbox][version] = 7.x-1.1

;Libraries
libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.1/ckeditor_3.6.1.tar.gz"
libraries[ckeditor][directory_name] = "ckeditor"
libraries[colorbox][download][type] = "get"
libraries[colorbox][download][url] = "http://colorpowered.com/colorbox/colorbox.zip"
libraries[colorbox][directory_name] = "colorbox"
libraries[htmlpurifier][download][type] = "get"
libraries[htmlpurifier][download][url] = "http://htmlpurifier.org/releases/htmlpurifier-4.3.0-lite.tar.gz"
libraries[htmlpurifier][directory_name] = "htmlpurifier"

;Strongleg
projects[strongleg][type] = module
projects[strongleg][download][type] = git
projects[strongleg][download][url] = http://git.drupal.org/project/strongleg.git

;Interface
projects[panels][version] = 7.x-3.0-alpha3
projects[ds][version] = 7.x-1.3

;Misc Contrib
projects[advanced_help][version] = 7.x-1.0-beta1
projects[webform][version] = 7.x-3.13
projects[token][version] = 7.x-1.0-beta5
projects[variable][version] = 7.x-1.1
projects[taxonomy_manager][version] = 7.x-1.0-beta2
projects[scheduler_manager][version] = 7.x-1.0
projects[rules][version] = 7.x-2.0-rc1
projects[role_delegation][version] = 7.x-1.1
projects[pathologic][version] = 7.x-1.3
projects[pathauto][version] = 7.x-1.0-rc2
projects[pagepreview][version] = 7.x-1.x-dev
projects[module_filter][version] = 7.x-1.5
projects[masquerade][version] = 7.x-1.0-rc3
projects[link][version] = 7.x-1.x-alpha3
projects[field_group][version] = 7.x-1.0
projects[facetapi][version] = 7.x-1.x-beta6
projects[extlink][version] = 7.x-1.12
projects[entity][version] = 7.x-1.0-beta10
projects[custom_breadcrumbs][version] = 7.x-1.0-alpha1
projects[context][version] = 7.x-3.0-beta2
projects[conditional_styles][version] = 7.x-2.0
projects[backup_migrate][version] = 7.x-2.2



