Pod::Spec.new do |s|
  s.name         = "RealmUtilities"
  s.version      = "0.3"
  s.summary      = "Various utility classes/categories to simplify using Realm."
  s.description  = <<-DESC
Categories that work with various Realm classes to simplify working with Realm.
                   DESC
  s.homepage     = "https://github.com/Roobiq/RealmUtilities"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "Roobiq" => "support@roobiq.com" }
  s.social_media_url   = "http://twitter.com/Roobiq"
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/Roobiq/RealmUtilities.git", :tag => "v#{s.version}"}
  s.source_files  = "*.{h,m}"
  s.requires_arc = true
  s.dependency 'Realm', '>= 0.95'

end
