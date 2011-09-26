
/**
 * @file node_export_file_admin.js
 *  Admin DHTML for node_export_file module.
 **/

(function ($) {

  Drupal.behaviors.nodeExportFileAdmin = {
    attach: function (context, settings) {

      var assets_state = false; // Start hidden
      var file_mode = null;
      var assets_div = $('div.node-export-file-assets-wrapper', context);

      // On load, hide or show the assets path
      file_mode = $('input[name="node_export_file_mode"]:checked', context).val();
      assets_state = _node_export_file_get_state(file_mode);

      _node_export_file_toggle_export_mode_warning(file_mode);
      _node_export_file_assets_toggle(assets_state, assets_div, 'hide');

      $('input[name="node_export_file_mode"]', context).change(function () {
        assets_state = _node_export_file_get_state($(this, context).val())
        _node_export_file_assets_toggle(assets_state, assets_div, 'slide');
        _node_export_file_toggle_export_mode_warning($(this, context).val());
      });

      $('input[name="node_export_code"]', context).change(function () {
        _node_export_file_toggle_export_mode_warning($('input[name="node_export_file_mode"]', context).val(), context);
      });
    }
  };

  /**
   * Get state based on input value.
   **/
  function _node_export_file_get_state(value) {
    switch (value) {
      default:
      case 'remote':
        return false;

      case 'local':
        return true;
    }
  }

  /**
   * Basic show/hide controller.
   **/
  function _node_export_file_assets_toggle(state, div, effect) {
    if (state) {
      if (effect == 'hide') {
        div.show();
      } else {
        div.slideDown();
      }
    } else {
      if (effect == 'hide') {
        div.hide();
      } else {
        div.slideUp();
      }
    }
  }

  /**
   * Toggles the file mode warning message.
   */
  function _node_export_file_toggle_export_mode_warning(state, context) {
    if (state == 'inline') {
      if ($('#edit-node-export-code-copy:checked', context).length == 0) {
        $('#node-export-file-mode-message', context).slideUp();
      }
      else {
        $('#node-export-file-mode-message', context).slideDown();
      }
    }
    else {
      $('#node-export-file-mode-message', context).slideUp();
    }
  }

})(jQuery);