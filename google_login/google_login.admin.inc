<?php
/**
 * @file
 * Administration pages for Google Login settings.
 */

/**
 * Implements hook_form().
 */

function google_login_settings_form() {
  $form = array();

  $form['after_login_path'] = array(
    '#type' => 'textfield',
    '#title' => t('The redirect path after login'),
    '#default_value' => variable_get('after_login_path', ''), 
    '#maxlength' => 255,
  );
  $form['css_file'] = array(
    '#type' => 'textfield',
    '#title' => t('The name of the css file to be used'),
    '#default_value' => variable_get('css_file', ''), 
    '#maxlength' => 255,
  );
/*
  $form['auth_cancel'] = array(
    '#type' => 'textfield',
    '#title' => t('The message when canceling the login'),
    '#default_value' => variable_get('auth_cancel', ""), 
    '#maxlength' => 255,
  );
  $form['validation_failed'] = array(
    '#type' => 'textfield',
    '#title' => t('The message for a failed validation'),
    '#default_value' => variable_get('validation_failed', ""), 
    '#maxlength' => 255,
  );
  $form['login_failed'] = array(
    '#type' => 'textfield',
    '#title' => t('The message for a failed login'),
    '#default_value' => variable_get('login_failed', ""), 
    '#maxlength' => 255,
  );
  $form['validation_success'] = array(
    '#type' => 'textfield',
    '#title' => t('The message for a successful validation'),
    '#default_value' => variable_get('validation_success', ""), 
    '#maxlength' => 255,
  );
*/
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#suffix' => l(t('Cancel'), 'admin/modules'),
  );
  return $form;
}

/**
 * Implements hook_form_submit().
 */

function google_login_settings_form_submit($form, &$form_state) {
  // Exclude unnecessary elements.
  form_state_values_clean($form_state);

  foreach ($form_state['values'] as $key => $value) {
    if (is_array($value) && isset($form_state['values']['array_filter'])) {
      $value = array_keys(array_filter($value));
    }
    variable_set($key, $value);
  }
  drupal_set_message(t('The configuration have been saved.'));
}
