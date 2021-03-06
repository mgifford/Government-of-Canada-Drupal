<?php
// $Id: html.tpl.php,v 1.6 2010/11/24 03:30:59 webchick Exp $

/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
  "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>
	<head>
		<!-- Web Experience Toolkit (WET) / Boîte à outils de l'expérience Web (BOEW)
		Terms and conditions of use: http://tbs-sct.ircan.gc.ca/projects/gcwwwtemplates/wiki/Terms
		Conditions régissant l'utilisation : http://tbs-sct.ircan.gc.ca/projects/gcwwwtemplates/wiki/Conditions
		-->	
		
		<!-- Title begins / Début du titre -->
		<title><?php print $head_title; ?></title>
		<!-- Title ends / Fin du titre -->
    
		<!-- Specified Meta-data begins / Début des métadonnées -->
    <meta name="title" content="<?php print $head_title; ?>" />
    <?php if ($language->language == 'en'): ?>
    <meta name="dc.creator" content="Government of Canada | Gouvernment du Canada" />
    <meta name="dc.language" scheme="ISO639-2/T" content="eng" />
    <?php endif; ?>
    <?php if ($language->language == 'fr'): ?>
    <meta name="dc.creator" content="Gouvernment du Canada | Government of Canada" />
    <meta name="dc.language" scheme="ISO639-2/T" content="fra" />
    <?php endif; ?>
  	<!-- Specified Meta-data ends / Fin des métadonnées -->
    
    <!-- Module Driven Meta-data begins / Début des métadonnées -->
    <?php print $head; ?>
    <!-- Module Driven Meta-data ends / Fin des métadonnées -->

		<!-- WET scripts/CSS begin / Début des scripts/CSS de la BOEW -->
		<?php print $styles; ?>
		<!-- WET scripts/CSS end / Fin des scripts/CSS de la BOEW -->
			
		<!-- Progressive enhancement begins / Début de l'amélioration progressive -->		
		<!-- Progressive enhancement ends / Fin de l'amélioration progressive -->

		<!-- Custom scripts/CSS begin / Début des scripts/CSS personnalisés -->
		<?php print $scripts; ?>
		<!-- Custom scripts/CSS end / Fin des scripts/CSS personnalisés -->

	</head>

	<body class="<?php print $classes; ?>" <?php print $attributes;?>>
		<?php print $page_top; ?>
		<?php print $page; ?>
		<?php print $page_bottom; ?>
	</body>
</html>
