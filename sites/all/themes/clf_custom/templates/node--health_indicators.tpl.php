<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print $user_picture; ?>
  <?php print render($title_prefix); ?>
  
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  
  <?php print render($title_suffix); ?>
 
  <?php if ($display_submitted): ?>
    <div class="submitted">
      <?php print $submitted; ?>
    </div>
  <?php endif; ?>
  
  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
    ?>
    <div id="tab-container">
    <?php if ($field_definition): ?>
			<ul class="tabs" role="tablist">
          <li role="presentation">
            <a aria-selected="false" href="#tab0" id="tab0-link" role="tab">
                Definition
            </a>
          </li>
          <li role="presentation">
            <a aria-selected="false" href="#tab1" id="tab1-link" role="tab">
                Data
            </a>
          </li>
          <li role="presentation">
            <a aria-selected="false" href="#tab2" id="tab2-link" role="tab">
                Factsheet
            </a>
          </li>
          <li role="presentation">
            <a aria-selected="false" href="#tab3" id="tab3-link" role="tab">
                Maps
            </a>
          </li> 
      </ul>
      <div class="tabs-panel">    
        <!-- Definition Section -->
        <div aria-hidden="true" aria-labelledby="tab0-link" class="active" id="tab0" role="tabpanel" style="display: none; ">
            <section>
              <?php if ($field_definition): ?>
                <?php print render($content['field_definition']); ?>
              <?php endif; ?>
            </section>
        </div>
        
        <!-- Data Tables Section -->
        <div aria-hidden="true" aria-labelledby="tab1-link" class="active" id="tab1" role="tabpanel" style="display: none; ">
            <section>
              <?php if ($field_tables_key): ?>
               <?php foreach ($field_tables_key as $delta => $item) : ?>
                  <div id="visualize-links">
                    <?php $delta_count = $delta + 1; ?>
                    <strong>Table <?php print $delta_count; ?> Visualization: </strong>
                      <li><a href="#" id="bar_link<?php print $delta_count; ?>">Bar</a></li>
                      <li><a href="#" id="pie_link<?php print $delta_count; ?>">Pie</a></li>
                      <li><a href="#" id="line_link<?php print $delta_count; ?>">Line</a></li>
                      <li><a href="#" id="area_link<?php print $delta_count; ?>">Area</a></li>
                  </div>
                  <div id="visualize-wrapper<?php print $delta_count; ?>">
                    <?php if ($field_tables): ?>
                      <?php print $field_tables[$delta]['value']; ?> 
                    <?php endif; ?>
                  </div>
                <?php endforeach; ?>
              <?php endif; ?>
              <div id="graphme-container1">&nbsp;</div>
            </section>
        </div>
        
        <!-- Factsheet Section -->
        <div aria-hidden="true" aria-labelledby="tab2-link" class="active" id="tab2" role="tabpanel" style="display: none; ">
            <section>
              <?php if ($field_factsheet): ?>
               <?php print render($content['field_factsheet']); ?>
                 <?php foreach ($field_charts as $delta => $item) : ?>
                  <div id="hide_desc<?php print $delta ?>" class="hide_desc">
                    <?php print render($content['field_charts'][$delta]); ?> 
                  </div>
                <?php endforeach; ?>
              <?php endif; ?>
            </section>
        </div>
         
        <!-- Maps Section -->
        <div aria-hidden="true" aria-labelledby="tab3-link" class="active" id="tab3" role="tabpanel" style="display: none; ">
            <section>
              <?php if ($field_maps): ?>
                <?php print render($content['field_maps']); ?>
              <?php endif; ?>
            </section>
        </div>
      </div>
    <?php endif; ?>
    </div>
  </div>
  <?php print render($content['links']); ?>
  <?php print render($content['comments']); ?>
</div>