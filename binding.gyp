{
  'targets': [
    {
      'target_name': 'winiputils',
      'sources': [
        'src/binding.cc',
      ],
      'conditions': [
        [ 'OS=="win"', {
          'include_dirs': [
          ],
          'defines': [
          ],
          'conditions': [
            [ 'target_arch=="ia32"', {
              'link_settings': {
                'libraries': ['ws2_32.lib'],
              },
            }, {
              'link_settings': {
                'libraries': ['ws2_32.lib'],
              },
            }],
          ],
        }, {
          # POSIX
          'link_settings': {
            'libraries': [],
          },
        }],
      ],
    },
  ],
}