<?php

/**
 * Implementation of hook_captcha_default_points().
 */
function general_captcha_default_points() {
  $export = array();
  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'contact_mail_page';
  $captcha->module = '';
  $captcha->captcha_type = '';

  $export['contact_mail_page'] = $captcha;
  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'contact_mail_user';
  $captcha->module = '';
  $captcha->captcha_type = '';

  $export['contact_mail_user'] = $captcha;
  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_login';
  $captcha->module = '';
  $captcha->captcha_type = '';

  $export['user_login'] = $captcha;
  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_login_block';
  $captcha->module = '';
  $captcha->captcha_type = '';

  $export['user_login_block'] = $captcha;
  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_pass';
  $captcha->module = '';
  $captcha->captcha_type = '';

  $export['user_pass'] = $captcha;
  $captcha = new stdClass;
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'user_register';
  $captcha->module = '';
  $captcha->captcha_type = 'default';

  $export['user_register'] = $captcha;
  return $export;
}
