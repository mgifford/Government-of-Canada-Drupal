(function ($) {

Drupal.behaviors.facetapi = {
  attach: function(context, settings) {
    // Ensures ALL soft limit select boxes are updated.
    // @see http://drupal.org/node/735528
    $('select[name="soft_limit"]').change(function() {
      $('select[name="soft_limit"]').val($(this).val());
    });

    // Handles bug where input format fieldset is not hidden.
    // @see http://drupal.org/node/997826
    if ($('select[name="empty_behavior"]').val() != 'text') {
      $('fieldset#edit-empty-text-format').hide();
    }
    $('select[name="empty_behavior"]').change(function() {
      if ($(this).val() != 'text') {
        $('fieldset#edit-empty-text-format').hide();
      }
      else {
        $('fieldset#edit-empty-text-format').show();
      }
    });
  }
}

})(jQuery);
